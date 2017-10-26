#include "player.h"
#include "bhop.h"
#include "util.h"

#ifndef MAIN_H_
#define MAIN_H_

namespace Main {
	extern Player player;
	extern Bunnyhop bhop;
	extern HWND window;
	extern DWORD pid;
	extern DWORD module_base;
	extern Util util;
	extern HANDLE process;
	extern DWORD player_base;
	extern DWORD mflags;
	extern POINT center;
	extern POINT cursor_pos;
	extern bool bhop_enabled;
}

#endif
