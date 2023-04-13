using DotPatch.Api;
using System.Runtime.InteropServices;

namespace DotPatch.Runtime.Managed;

internal class HookServiceImpl : IHookService
{
    delegate int MessageBoxA(IntPtr hWnd, string lpText, string lpCaption, uint uType);
    MessageBoxA MessageBoxAOrig;
    int MessageBoxAHook(IntPtr hWnd, string lpText, string lpCaption, uint uType)
    {
        return MessageBoxAOrig(hWnd, "I have been replaced from a csharp hook", lpCaption, uType);
    }

    public void CreateHook()
    {
        var target = NativeInterface.GetProcAddress(
            NativeInterface.GetModuleHandleA("user32.dll"),
            "MessageBoxA"
        );
        var hook = Marshal.GetFunctionPointerForDelegate<MessageBoxA>(MessageBoxAHook);

        IntPtr original = IntPtr.Zero;
        NativeInterface.CreateHook(target, hook, ref original);
        MessageBoxAOrig = Marshal.GetDelegateForFunctionPointer<MessageBoxA>(original);
    }

    public void RemoveHook()
    {
        var target = NativeInterface.GetProcAddress(
            NativeInterface.GetModuleHandleA("user32"),
            "MessageBoxA"
        );

        NativeInterface.RemoveHook(target);
    }
}
