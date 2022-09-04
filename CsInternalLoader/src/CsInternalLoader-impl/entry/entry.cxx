#include "entry.cc"

#include <CsInternalLoader-impl/loader/inc>

namespace Chrones::IO::Samples::CsInternalLoader
{
	/**
	 * Executed when loaded.
	 */
	auto Entry() -> void
	{
		// Executing our loader
		Loader::LoadCsInternalClient();
	}
}