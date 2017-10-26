#include "main.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace Main;
using namespace std;

DWORD Main::player_base = 0x70DC44;
DWORD Main::mflags = 0x350;
Player Main::player;
Bunnyhop Main::bhop;
Util Main::util;
HWND Main::window;
DWORD Main::pid;
DWORD Main::module_base;
HANDLE Main::process;
POINT Main::center;
bool Main::bhop_enabled;


int main() {
	printf("Waiting for Garry's Mod.\n");
	window = FindWindow(NULL, "Garry's Mod");
	while (window == NULL) {
		Sleep(1000);
		window = FindWindow(NULL, "Garry's Mod");
	}
	printf("Garry's Mod was found.\n");
	GetWindowThreadProcessId(window, &pid);
	process = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	module_base = util.get_module_base_extern(pid, "client.dll");
	player.start();
	bhop.start();
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD0)) {
			bhop_enabled = false;
		}
		  else if (GetAsyncKeyState(VK_NUMPAD1)) {
			bhop_enabled = true;
		}
	}
	return 0;
}
