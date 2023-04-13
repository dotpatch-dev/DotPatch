using DotPatch.Api;
using DotPatch.Example.NierReplicantRemake;
using Microsoft.Extensions.DependencyInjection;

namespace DotPatch.Runtime.Managed;

internal class PatchManager
{
    private readonly Type[] _builtinPatches = new Type[]
    {
        typeof(NierReplicantRemakePatch)
    };

    private readonly IServiceCollection _serviceCollection = new ServiceCollection();
    private IServiceProvider? _serviceProvider;

    internal static PatchManager Instance { get; private set; } = new();

    public void InitializePatches()
    {
        _serviceCollection.AddSingleton<IHookService, HookServiceImpl>();

        foreach (var patchType in _builtinPatches)
        {
            _serviceCollection.AddSingleton(patchType);
        }

        _serviceProvider = _serviceCollection.BuildServiceProvider();

        foreach (var patchType in _builtinPatches)
        {
            var patch = (IPatch) _serviceProvider.GetService(patchType)!;
            patch.Load();
        }
    }
}
