#include "players.hpp"

#include "../../globals/proc.hpp"
#include "../offsets/offset.hpp"

namespace rbx
{
	auto players::local_player( ) -> player
	{
		return proc->read<std::uint32_t>( this->address + offset.local_player );
	}

	auto players::get_players( ) -> std::vector<player>
	{
		std::vector<player> players = {};

		for (instance player : this->get_children( ))
			players.push_back( player.address );

		return players;
	}
}