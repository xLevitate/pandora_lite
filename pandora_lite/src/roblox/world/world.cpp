#include "world.hpp"

#include "../../globals/globals.hpp"
#include "../../globals/proc.hpp"

#include "../task_scheduler/task_scheduler.hpp"

namespace rbx
{
	void c_world::initialize( )
	{
		globals.datamodel = rbx::scheduler.get_datamodel( );
		std::printf( "roblox -> datamodel: %x\n", globals.datamodel.address );

		globals.visualengine = rbx::scheduler.get_visual_engine( );
		std::printf( "roblox -> visualengine: %x\n", globals.visualengine.address );

		globals.workspace = globals.datamodel.get_service( "Workspace" );
		std::printf( "roblox -> workspace: %x\n", globals.workspace.address );

		globals.players = globals.datamodel.get_service( "Players" ).address;
		std::printf( "roblox -> players: %x\n", globals.players.address );

		globals.local_player = globals.players.local_player( );
		std::printf( "roblox -> local_player: %x\n\n", globals.local_player.address );
	}

	void c_world::update( )
	{
		while (true)
		{
			globals.player_list = globals.players.get_players( );

			std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
		}
	}

	c_world world;
}