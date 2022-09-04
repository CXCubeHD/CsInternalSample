/**
 * This part is for the Clang compiler only.
 */
#ifdef __clang__

#include <Windows.h>

#include "entry.cc"

static WINAPI auto WinEntry(HMODULE hModule) -> int
{
	// Call out Entry function
	Chrones::IO::Samples::CsInternalLoader::Entry();

	// Unload this DLL
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}

/**
 * Entry point of our Clang compiled DLL. Since Clang does not provide DllMain we can just use that.
 */
__attribute__((constructor)) auto LibraryMain() -> void
{
	auto hInstance = GetModuleHandle(nullptr);
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) WinEntry, hInstance, 0, nullptr);
}

#endif