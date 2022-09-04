using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Chrones.IO.Samples.CsInternalClient;

/// <summary>
/// Represents the entry of this client. Contains the loader function in it.
/// </summary>
public static class Entry
{
    [UnmanagedCallersOnly(EntryPoint = "_Load_CsInternalClient", CallConvs = new[] { typeof(CallConvStdcall) })]
    internal static void Load()
    {
        
    }
}