#pragma once
#include <windows.h>
#include <iostream>

#include "..\roblox\datamodel\datamodel.hpp"
#include "..\roblox\visualengine\visualengine.hpp"
#include "..\roblox\players\players.hpp"
#include "..\roblox\player\player.hpp"

struct globals_t
{
	static rbx::datamodel datamodel;
	static rbx::visualengine visualengine;
	static rbx::instance workspace;
	static rbx::players players;
	static rbx::player local_player;

	static std::vector<rbx::player> player_list;
};

inline globals_t globals;