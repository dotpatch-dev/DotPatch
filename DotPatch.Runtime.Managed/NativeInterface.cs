using System.Runtime.InteropServices;

namespace DotPatch.Runtime.Managed;

public static class NativeInterface
{
    public delegate void EntrypointDelegate();

    public static void Entrypoint()
    {
        Console.WriteLine("Entrypoint!!!");

        PatchManager.Instance.InitializePatches();
    }

    [DllImport("DotPatch.Runtime.Native")]
    public extern static void CreateHook(IntPtr target, IntPtr hook, ref IntPtr original);


    [DllImport("DotPatch.Runtime.Native")]
    public extern static void RemoveHook(IntPtr target);

    [DllImport("kernel32")]
    public extern static IntPtr GetModuleHandleA(string moduleName);

    [DllImport("kernel32")]
    public extern static IntPtr GetProcAddress(IntPtr moduleHandle, string exportName);
}
