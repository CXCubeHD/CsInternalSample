#include <Windows.h>

#include "loader.cc"

#include <CsInternalLoader-impl/config/inc>
#include <CsInternalLoader-impl/helper/inc>

using namespace std::chrono_literals;

namespace Chrones::IO::Samples::CsInternalLoader::Loader
{
	auto LoadCsInternalClient() -> void
	{
		if (Config::CsInternalClientPath.empty())
		{
			ConsoleHelper::CreateConsole();
			SetConsoleTitleW(L"CsInternalLoader Console");

			chr::cout << "Chrones::IO::Samples::CsInternalLoader::Config::CsInternalClientPath";
			chr::cout << " was empty!" << chr::endl << chr::endl;

			chr::cout << "Make sure to set the correct DLL path of your CsInternalClient.dll";
			chr::cout << " (CsInternalLoader/src/CsInternalLoader-impl/config/config.cc)." << chr::endl << chr::endl;

			chr::cout << "Exiting in 5 seconds.";

			std::this_thread::sleep_for(5000ms);

			ConsoleHelper::DestroyConsole();
			return;
		}

		// Load the DLL into our process
		auto handle = LoadLibraryW(Config::CsInternalClientPath.c_str());

		if (handle == nullptr)
		{
			ConsoleHelper::CreateConsole();
			SetConsoleTitleW(L"CsInternalLoader Console");

			chr::cout << "Error: LoadLibraryW(Config::CsInternalClientPath.c_str()) returned null!";
			chr::cout << chr::endl << chr::endl;

			chr::cout << "Exiting in 5 seconds.";

			std::this_thread::sleep_for(5000ms);

			ConsoleHelper::DestroyConsole();
			return;
		}

		// (Safety Sleep (making sure the DLL has enough time to initialize its runtime))
		std::this_thread::sleep_for(100ms);

		// Getting the function pointer to our _Load_CsInternalClient function
		auto loadFunc = (void (__stdcall *)()) GetProcAddress(handle, Config::CsInternalClientLoadFunction.c_str());

		if (loadFunc == nullptr)
		{
			ConsoleHelper::CreateConsole();
			SetConsoleTitleW(L"CsInternalLoader Console");

			chr::cout << "Error: GetProcAddress(handle, Config::CsInternalClientLoadFunction.c_str()) returned null!";
			chr::cout << chr::endl << chr::endl;

			chr::cout << "Exiting in 5 seconds.";

			std::this_thread::sleep_for(5000ms);

			ConsoleHelper::DestroyConsole();
			return;
		}

		// Executing our _Load_CsInternalClient function ^^
		loadFunc();
	}
}