#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <chrono>

namespace rbx
{
	class c_world
	{
	public:
		void initialize( );

		void update( );
	};

	extern c_world world;
}