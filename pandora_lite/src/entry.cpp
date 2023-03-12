#include <windows.h>
#include <iostream>

#include "globals\globals.hpp"

#include "roblox\task_scheduler\task_scheduler.hpp"
#include "roblox\world\world.hpp"

#include "overlay\overlay.hpp"

auto main( ) -> int
{
	SetConsoleTitle( "pandora lite - v2023.3.12" );

	// Initialize the task scheduler
	rbx::scheduler.initialize( );

	// Get datamodel, visualengine, etc
	rbx::world.initialize( );

	// Update the player list, etc
	std::thread( []
		{
			rbx::world.update( );
		} ).detach( );

	// Initialize the overlay
	overlay.initialize( );

	std::cin.get( );
	return 0;
}