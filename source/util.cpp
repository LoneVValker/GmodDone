#include "util.h"
#include <ctime>
#include <Tlhelp32.h>

DWORD Util::get_module_base_extern(const DWORD dw_process_id, const char *sz_module_name) {
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dw_process_id);
	if (!snap) {
		return 0;
	}
	MODULEENTRY32 module_entry;
	module_entry.dwSize = sizeof(MODULEENTRY32);
	DWORD dw_return = 0;
	if (Module32First(snap, &module_entry)) {
		while (Module32Next(snap, &module_entry)) {
			if (lstrcmpi(module_entry.szModule, sz_module_name) == 0) {
				dw_return = (DWORD) module_entry.modBaseAddr;
				break;
			}
		}
	}
	CloseHandle(snap);
	return dw_return;
}

