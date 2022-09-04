namespace Chrones.IO.Samples.CsInternalClient.Helpers;

public static class ConsoleHelper
{
    public static void CreateOutputConsole()
    {
        var result = Windows.Win32.PInvoke.AllocConsole();

        var stdHandle = Windows.Win32.PInvoke.CreateFile(
            "CONOUT$",
            Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.FILE_GENERIC_WRITE,
            Windows.Win32.Storage.FileSystem.FILE_SHARE_MODE.FILE_SHARE_WRITE,
            lpSecurityAttributes: default,
            Windows.Win32.Storage.FileSystem.FILE_CREATION_DISPOSITION.OPEN_EXISTING,
            dwFlagsAndAttributes: default,
            hTemplateFile: null);
        var fileStream = new FileStream(stdHandle, FileAccess.Write);
        StreamWriter standardOutput = new StreamWriter(fileStream, System.Text.Encoding.ASCII);
        standardOutput.AutoFlush = true;
        Console.SetOut(standardOutput);
    }
}