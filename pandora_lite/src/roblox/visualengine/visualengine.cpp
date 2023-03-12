#include "visualengine.hpp"

#include "../../globals/proc.hpp"
#include "..\offsets\offset.hpp"

namespace rbx
{
	auto visualengine::client_dimensions( ) -> vec2 
	{
		return proc->read<vec2>( this->address + offset.dimensions );
	}

	auto visualengine::view_matrix( ) -> float* 
	{
		return proc->read<float*>( this->address + offset.view_matrix );
	}

	auto visualengine::camera_position( ) -> vec3 
	{
		return proc->read<vec3>( this->address + offset.camera_position );
	}

	auto visualengine::world_to_screen( vec3 position ) -> bool 
	{
		
	}
}