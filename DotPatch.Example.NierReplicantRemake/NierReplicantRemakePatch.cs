using DotPatch.Api;
using DotPatch.Api.Marshalling;
using System.Diagnostics;

namespace DotPatch.Example.NierReplicantRemake;

public class NierReplicantRemakePatch : IPatch
{
    private readonly IHookService _hookService;

    private NativeBox<string> _levelString = null!;

    public NierReplicantRemakePatch(IHookService hookService)
    {
        _hookService = hookService;
    }

    public void Load()
    {
        Console.WriteLine("Nier Replicant meme");
        _hookService.CreateHook();
        return;
        var replicantModule = Process
            .GetCurrentProcess()
            .MainModule;

        _levelString = new NativeBox<string>(replicantModule.BaseAddress + 0x15C3163);
        Console.WriteLine($"Current level: {_levelString.Value}");
    }

    public void Unload()
    {
        throw new NotImplementedException();
    }
}
