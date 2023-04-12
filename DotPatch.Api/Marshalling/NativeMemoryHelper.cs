using System.Runtime.InteropServices;
using System.Text;

namespace DotPatch.Api.Marshalling;

public class NativeBox<T>
{
    public IntPtr Address { get; set; }

    public NativeBox(IntPtr address) { Address = address; }

    public T Value
    {
        get
        {
            switch ((Nullable.GetUnderlyingType(typeof(T)) ?? typeof(T)).Name)
            {
                case nameof(String):
                    return (T) (object) Marshal.PtrToStringUTF8(Address)!;

                default:
                    return Marshal.PtrToStructure<T>(Address)!;
            }
        }
        set
        {
            switch ((Nullable.GetUnderlyingType(typeof(T)) ?? typeof(T)).Name)
            {
                case nameof(String):
                    var buffer = Encoding.UTF8.GetBytes(value as string);
                    Marshal.Copy(buffer, 0, Address, buffer.Length);
                    break;

                default:
                    Marshal.StructureToPtr(value!, Address, false);
                    break;
            }
        }
    }
}
