#include "main.h"

using namespace Main;

/*
 FL_IN_AIR_STAND                    256
 FL_IN_AIR_MOVING_TO_STAND         258
 FL_IN_AIR_MOVING_TO_CROUCH         260
 FL_IN_AIR_CROUCHED                 262
 FL_IN_AIR_PUDDLE                     1280
 FL_IN_AIR_PUDDLE_CROUCHED             1282
 */

int p_base;
int flag;

void read_memory() {
	while (true) {
		if (bhop_enabled) {
			ReadProcessMemory(process, (LPVOID) (module_base + player_base), &p_base, sizeof(int), NULL);
			ReadProcessMemory(process, (LPVOID) (p_base + mflags), &flag, sizeof(int), NULL);
			Sleep(1);
		} else {
			Sleep(1);
		}
	}
}

void Player::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) read_memory, NULL, 0, NULL);
}

bool Player::in_air() {
	return flag == 256 || flag == 258 || flag == 260 || flag == 262 || flag == 1280 || flag == 1282;
}

