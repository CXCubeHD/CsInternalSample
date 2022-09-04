#include <Windows.h>

#include <chr-core>

#include "console-helper.cc"

static FILE* StdIn_ = { };
static FILE* StdOut_ = { };
static FILE* StdErr_ = { };

namespace Chrones::IO::Samples::CsInternalLoader::ConsoleHelper
{
	static bool IsConsoleCreated_ = false;
	auto GetIsConsoleCreated() -> bool { return IsConsoleCreated_; }

	auto CreateConsole() -> void
	{
		if (IsConsoleCreated_) return;

		if (!::AllocConsole()) throw chr::err("AllocConsole returned false.");

		freopen_s(&StdIn_, "CONIN$", "r", stdin);
		freopen_s(&StdOut_, "CONOUT$", "w", stderr);
		freopen_s(&StdErr_, "CONOUT$", "w", stdout);

		IsConsoleCreated_ = true;
	}

	auto DestroyConsole() -> void
	{
		if (!IsConsoleCreated_) return;

		::FreeConsole();

		fclose(StdIn_);
		fclose(StdOut_);
		fclose(StdErr_);

		IsConsoleCreated_ = false;
	}

	auto EnableConsoleAnsiCodes() -> void
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hOut == INVALID_HANDLE_VALUE) throw chr::err("GetStdHandle failed.");

		DWORD dwMode = 0;
		if (!GetConsoleMode(hOut, &dwMode)) throw chr::err("GetConsoleMode failed.");

		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		if (!SetConsoleMode(hOut, dwMode)) throw chr::err("SetConsoleMode failed.");
	}
}