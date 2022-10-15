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
    internal static void Load_()
    {
        new Thread(Main).Start();
    }

    /// <summary>
    /// This is it, you can start doing your own things :D
    /// </summary>
    public static async void Main()
    {
        Helpers.ConsoleHelper.CreateConsole();

        Console.Title = "CsInternalClient";
        
        Console.WriteLine("Hello World!");
        
        Console.Write("What is your name? Name: ");
        var name = Console.ReadLine();
        
        Console.WriteLine("Oh, it looks like your name is: {0}", name);
        
        await Task.Delay(-1);
    }
}