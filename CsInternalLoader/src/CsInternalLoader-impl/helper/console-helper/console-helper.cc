#pragma once

namespace Chrones::IO::Samples::CsInternalLoader::ConsoleHelper
{
	auto GetIsConsoleCreated() -> bool;

	auto CreateConsole() -> void;
	auto DestroyConsole() -> void;

	auto EnableConsoleAnsiCodes() -> void;
}