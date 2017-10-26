#include <Windows.h>

#ifndef UTIL_H_
#define UTIL_H_

class Util {
	public:
		DWORD get_module_base_extern(const DWORD dw_process_id, const char *sz_module_name);
};

#endif
