# CsInternalSample

This sample uses the power of C# and .NET NativeAOT to create an 
injectable client.

Since I didn't find a known way to execute code in C# when injected,
I had to make this client depended from another C++ DLL (which gets
injected first). This C++ DLL then loads our C# DLL and calls the 
`Load_` function which we exported as `_Load_CsInternalClient`.

```cs
[UnmanagedCallersOnly(EntryPoint = "_Load_CsInternalClient", CallConvs = new[] { typeof(CallConvStdcall) })]
internal static void Load_()
{
    ...
}
```

# Building

Make sure to clone this repo using the `--recursive` flag:
```bash
git clone --recursive https://github.com/CXCubeHD/CsInternalSample
```

You can create the NativeAOT C# DLL _(CsInternalClient)_ using:
```bash
dotnet publish -r win-x64 -c Release
```

If it doesn't say 
`Generating compatible native code. To optimize for size or speed, visit https://aka.ms/OptimizeNativeAOT`
then you probably did something wrong.

The compiled DLL should appear at this location:
`.\CsInternalClient\bin\Release\net7.0-windows10.0.22621.0\win-x64\native`

Then tell the C++ DLL where our DLL is located by editing this file:
`.\CsInternalLoader\src\CsInternalLoader-impl\config\config.cc`

```c++
// TODO: Enter the path of your CsInternalClient DLL
inline chr::wstr CsInternalClientPath =
	L"PATH TO NativeAOT C# DLL";
```

If you are trying to inject those DLLs into a UWP app then make sure
they both have the required file permissions.

Lastly compile the C++ DLL _(CsInternalLoader)_ using CMake.

---

That's it now you can inject it!

# License

The license can be found under LICENSE.md.

Please note that currently the license is very strict so please
make sure to read it.