namespace Chrones.IO.Samples.CsInternalClient.Helpers;

public static class ConsoleHelper
{
    public static void CreateConsole()
    {
        var result = Windows.Win32.PInvoke.AllocConsole();

        var stdHandle0 = Windows.Win32.PInvoke.CreateFile(
            "CONIN$",
            Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.FILE_GENERIC_READ,
            Windows.Win32.Storage.FileSystem.FILE_SHARE_MODE.FILE_SHARE_READ,
            lpSecurityAttributes: default,
            Windows.Win32.Storage.FileSystem.FILE_CREATION_DISPOSITION.OPEN_EXISTING,
            dwFlagsAndAttributes: default,
            hTemplateFile: null);
        var fileStream0 = new FileStream(stdHandle0, FileAccess.Read);
        StreamReader standardInput = new StreamReader(fileStream0, System.Text.Encoding.ASCII);
        Console.SetIn(standardInput);
        
        var stdHandle1 = Windows.Win32.PInvoke.CreateFile(
            "CONOUT$",
            Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.FILE_GENERIC_WRITE,
            Windows.Win32.Storage.FileSystem.FILE_SHARE_MODE.FILE_SHARE_WRITE,
            lpSecurityAttributes: default,
            Windows.Win32.Storage.FileSystem.FILE_CREATION_DISPOSITION.OPEN_EXISTING,
            dwFlagsAndAttributes: default,
            hTemplateFile: null);
        var fileStream1 = new FileStream(stdHandle1, FileAccess.Write);
        StreamWriter standardOutput = new StreamWriter(fileStream1, System.Text.Encoding.ASCII);
        standardOutput.AutoFlush = true;
        Console.SetOut(standardOutput);
        
        var stdHandle2 = Windows.Win32.PInvoke.CreateFile(
            "CONOUT$",
            Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.FILE_GENERIC_WRITE,
            Windows.Win32.Storage.FileSystem.FILE_SHARE_MODE.FILE_SHARE_WRITE,
            lpSecurityAttributes: default,
            Windows.Win32.Storage.FileSystem.FILE_CREATION_DISPOSITION.OPEN_EXISTING,
            dwFlagsAndAttributes: default,
            hTemplateFile: null);
        var fileStream2 = new FileStream(stdHandle2, FileAccess.Write);
        StreamWriter standardError = new StreamWriter(fileStream2, System.Text.Encoding.ASCII);
        standardError.AutoFlush = true;
        Console.SetError(standardError);
    }
}