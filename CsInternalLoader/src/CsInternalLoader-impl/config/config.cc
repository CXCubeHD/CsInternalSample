#pragma once

#include <chr-core>

namespace Chrones::IO::Samples::CsInternalLoader::Config
{
	// TODO: Enter the path of your CsInternalClient DLL
	inline chr::wstr CsInternalClientPath =
		L"";

	inline chr::str CsInternalClientLoadFunction =
		"_Load_CsInternalClient";
}