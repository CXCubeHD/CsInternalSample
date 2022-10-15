#pragma once

#include <chr-core>

namespace Chrones::IO::Samples::CsInternalLoader::Config
{
	// TODO: Enter the path of your CsInternalClient DLL
	inline chr::wstr CsInternalClientPath =
		L"F:\\src\\CsInternalSample\\CsInternalSample\\CsInternalClient\\bin\\Release\\net7.0-windows10.0.22621.0\\win-x64\\native\\CsInternalClient.dll";

	inline chr::str CsInternalClientLoadFunction =
		"_Load_CsInternalClient";
}