#include "datamodel.hpp"

#include "../../globals/proc.hpp"
#include "../offsets/offset.hpp"

namespace rbx
{
	auto datamodel::get_service( std::string name ) -> instance {
		for (auto child : this->get_children( ))
			if (child.descriptor( ).class_name( ) == name)
				return child;

		return instance( 0xF );
	}

	auto datamodel::game_id( ) -> std::uint32_t {
		return proc->read<std::uint32_t>( this->address - 12 + offset.game_id );
	}
}