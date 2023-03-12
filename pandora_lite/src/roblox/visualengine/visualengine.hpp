#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

#include "../../utilities/math.hpp"

namespace rbx
{
	class visualengine 
	{
	public:
		visualengine( std::uint32_t addr ) : address( addr ) {};
		std::uint32_t address;

		auto client_dimensions( ) -> vec2;

		auto view_matrix( ) -> float*;

		auto camera_position( ) -> vec3;

		auto world_to_screen( vec3 position ) -> bool;
	};
}