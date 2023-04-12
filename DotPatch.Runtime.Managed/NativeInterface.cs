namespace DotPatch.Runtime.Managed;

public static class NativeInterface
{
    public delegate void EntrypointDelegate();

    public static void Entrypoint()
    {
        Console.WriteLine("Entrypoint!!!");

        PatchManager.Instance.InitializePatches();
    }
}
