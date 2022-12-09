#include "stdafx.h"

__shared_api_ void __stdcall VerifierOpenLayerProperties(void) {
	auto hConsoleWindow = ::GetConsoleWindow();
	::ShowWindow(hConsoleWindow, SW_HIDE);

	do {
		if (local::__gpGlobal)
			break;
		local::__gpGlobal = new local::Global();
		local::Global::UIMain()->Perfrom();
	} while (0);
	SK_DELETE_PTR(local::__gpGlobal);

	::TerminateProcess(::GetCurrentProcess(), 3762);
	::_exit(3762);
}//@23

__shared_api_ void __stdcall RouteDataCallback(const void* route, unsigned long route_size) {
	local::GlobalGet()->LaunchRouteRes(route, route_size);
}