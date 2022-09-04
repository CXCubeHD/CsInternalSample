using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace Chrones.IO.Samples.CsInternalClient;

/// <summary>
/// Represents the entry of this client. Contains the loader function in it.
/// </summary>
public static class Entry
{
    /// <summary>
    /// This method needs to be called from our loader in order to be able to run this client.
    /// </summary>
    [UnmanagedCallersOnly(EntryPoint = "_Load_CsInternalClient", CallConvs = new[] { typeof(CallConvStdcall) })]
    internal static void Load()
    {
        
    }
}