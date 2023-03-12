#include "player.hpp"

#include "../../globals/proc.hpp"
#include "..\offsets\offset.hpp"

namespace rbx
{
	auto player::team( ) -> instance
	{
		return proc->read<std::uint32_t>( this->address + offset.team );
	}

	auto player::character( ) -> instance
	{
		return proc->read<std::uint32_t>( this->address + offset.character );
	}
}