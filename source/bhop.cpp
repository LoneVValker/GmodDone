#include "main.h"

using namespace Main;

bool jumped;

void bhop_tick() {
	while (true) {
		if (bhop_enabled) {
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !player.in_air()) {
				SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
				jumped = true;
			}
			else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && player.in_air()) {
				SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
				if (jumped) {
					Sleep(16);
					SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
					SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
					jumped = false;
				}
			}
		}
	}
}

void Bunnyhop::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) bhop_tick, NULL, 0, NULL);
}

