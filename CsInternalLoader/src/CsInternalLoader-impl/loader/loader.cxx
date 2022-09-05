#include <Windows.h>

#include "loader.cc"

#include <CsInternalLoader-impl/helper/inc>

#pragma comment(lib, "CsInternalClient.lib")

/**
 * This function is required to initialize the compiled runtime of our client.
 */
extern "C" auto CoreRT_StaticInitialization() -> void*;

/**
 * Our _Load function
 */
extern "C" auto __stdcall _Load_CsInternalClient() -> void;

using namespace std::chrono_literals;

namespace Chrones::IO::Samples::CsInternalLoader::Loader
{
	auto LoadCsInternalClient() -> void
	{
		// We initialize all the required runtime stuff first
		CoreRT_StaticInitialization();

		std::this_thread::sleep_for(100ms);

		_Load_CsInternalClient();
	}
}