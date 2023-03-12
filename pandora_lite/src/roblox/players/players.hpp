#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

#include "../player/player.hpp"
#include "../instance/instance.hpp"

namespace rbx
{
	class players : public instance
	{
	public:
		using instance::instance;

		auto local_player( ) -> player;

		auto get_players( ) -> std::vector<player>;
	};
}