using DotPatch.Api.Marshalling;
using System.Runtime.InteropServices;

var buffer = Marshal.AllocHGlobal(512);
var box = new NativeBox<string>(buffer);

box.Value = "Hello World";
Console.WriteLine($"Value: {box.Value:X}");
