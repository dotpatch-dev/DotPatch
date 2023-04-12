using DotPatch.Api;
using DotPatch.Api.Marshalling;
using System.Diagnostics;

namespace DotPatch.Example.NierReplicantRemake;

public class NierReplicantRemakePatch : IPatch
{
    private NativeBox<string> _levelString = null!;
    public void Load()
    {
        Console.WriteLine("Nier Replicant meme");

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
