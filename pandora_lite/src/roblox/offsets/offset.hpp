#pragma once
#include <windows.h>
#include <cstdint>

namespace rbx {
	struct offset_t
	{
		// get_children
		std::uint32_t children = 0x2C;

		// parent
		std::uint32_t parent = 0x34;

		// primitive
		std::uint32_t primitive = 0xB8;

		// name
		std::uint32_t name = 0x28;

		// descriptor
		std::uint32_t descriptor = 0xC;

		// client_dimensions
		std::uint32_t dimensions = 0x6FC;

		// view_matrix
		std::uint32_t view_matrix = 0x170;

		// camera_position
		std::uint32_t camera_position = 0x90;

		// game_id
		std::uint32_t game_id = 0x3F8;

		// team
		std::uint32_t team = 0xA8;

		// character
		std::uint32_t character = 0x78;

		// local_player
		std::uint32_t local_player = 0x134;

		// position
		std::uint32_t position = 0xFC;

	};

	inline offset_t offset;
}