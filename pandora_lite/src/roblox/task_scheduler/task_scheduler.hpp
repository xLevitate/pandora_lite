#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

namespace rbx
{
	class task_scheduler
	{
	public:
		auto initialize( ) -> void;

		auto get_jobs( ) -> std::vector<std::uint32_t>;

		auto get_job( const std::string_view& name ) -> std::uint32_t;

		auto get_datamodel( ) -> std::uint32_t;

		auto get_visual_engine( ) -> std::uint32_t;
	private:
		std::uint32_t task_scheduler;
		std::uint32_t render;

		std::vector<std::uint32_t> jobs;
	};

	extern task_scheduler scheduler;
}