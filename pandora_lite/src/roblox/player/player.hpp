#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

#include "../instance/instance.hpp"

namespace rbx
{
	class player : public instance
	{
	public:
		using instance::instance;

		auto team( ) -> instance;

		auto character( ) -> instance;
	};
}