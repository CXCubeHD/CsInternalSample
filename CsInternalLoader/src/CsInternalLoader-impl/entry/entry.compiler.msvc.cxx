/**
 * This part is for the MSVC compiler only.
 */

// Clang may pretend to be MSVC ;)
#if defined(_MSC_VER) && !defined(__clang__)

#include <Windows.h>

#include "entry.cc"

static auto WINAPI WinEntry(HMODULE hModule) -> int
{
	// Call out Entry function
	Chrones::IO::Samples::CsInternalLoader::Entry();

	// Unload this DLL
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

/**
 * Entry point of our MSVC compiled DLL. Calls our Entry function when loaded into our target process.
 */
auto WINAPI DllMain(HMODULE hModule, int reason, void *reserved) -> bool
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			CloseHandle(
				CreateThread(
					nullptr, 0, (LPTHREAD_START_ROUTINE) Chrones::IO::Samples::CsInternalLoader::Entry, hModule, 0,
					nullptr
				));
			break;
		case DLL_PROCESS_DETACH:
			break;
		default:
			break;
	}

	return true;
}

#endif