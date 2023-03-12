#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

#include "..\..\utilities\math.hpp"

namespace rbx
{
	class instance 
	{
	public:
		std::uint32_t address;
		instance( std::uint32_t addr ) : address( addr ) {};

		// Gets the children of the instance
		auto get_children( ) -> std::vector<instance>;

		// Get child of the instance
		auto find_child( std::string name ) -> instance;

		// Get the parent of instance
		auto parent( ) -> instance;

		// Gets the primitive of the instance
		auto primitive( ) -> instance;

		// Gets the position of the instance
		auto position( ) -> vec3;

		// Gets the name of the instance
		auto name( ) -> std::string;

		// Gets the class name of the instance
		auto class_name( ) -> std::string;

		// Gets the class descriptor
		auto descriptor( ) -> instance;
	};
}