#pragma once
#include <windows.h>
#include <iostream>

#include "../instance/instance.hpp"

namespace rbx
{
	class datamodel : public instance
	{
	public:
		using instance::instance;

		auto get_service( std::string name ) -> instance;

		auto game_id( ) -> std::uint32_t;
	};
}