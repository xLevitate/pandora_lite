#include "instance.hpp"

#include "../../globals/proc.hpp"
#include "../offsets/offset.hpp"

namespace rbx
{
	auto instance::get_children( ) -> std::vector<instance>
	{
		auto container = proc->read<std::uint32_t>( this->address + 0x2C );

		if (container)
			return proc->read_vector<instance>( container );

		return std::vector<instance>( );
	}

	auto instance::find_child( std::string name ) -> instance
	{
		for (auto child : this->get_children( ))
			if (child.name( ) == name)
				return child;

		return instance( 0 );
	}

	auto instance::parent( ) -> instance
	{
		return proc->read<std::uint32_t>( this->address + offset.parent );
	}

	auto instance::primitive( ) -> instance
	{
		return proc->read<std::uint32_t>( this->address + offset.primitive );
	}

	auto instance::position( ) -> vec3
	{
		return proc->read<vec3>( this->address + offset.position );
	}

	auto instance::name( ) -> std::string
	{
		std::uint32_t name = proc->read<std::uint32_t>( this->address + offset.name );

		if (!name)
			return "unknown";

		return proc->read_str( name );
	}

	auto instance::class_name( ) -> std::string
	{
		return proc->read_str( proc->read<std::uint32_t>( this->address + 4 ) );
	}

	auto instance::descriptor( ) -> instance
	{
		return proc->read<std::uint32_t>( this->address + offset.descriptor );
	}
}