#include "task_scheduler.hpp"

#include "../../globals/proc.hpp"

namespace rbx
{
	auto task_scheduler::initialize( ) -> void
	{
		auto sig = proc->sig_scan(
			"\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x08\xE8\xDE\xAD\xBE\xEF\x8D\x0C\x24",
			"xxxxxxxxxx????xxx"
		);

		auto get_task_scheduler = proc->create_sub<std::uint32_t>( sig + 14 + proc->read<std::uint32_t>( sig + 10 ) );

		this->task_scheduler = get_task_scheduler( );
		std::printf( "roblox -> task_scheduler: %x\n", this->task_scheduler );

		this->jobs = this->get_jobs( );
		this->render = this->get_job( "Render" );
		std::printf( "roblox -> render: %x\n", this->render );
	}

	auto task_scheduler::get_jobs( ) -> std::vector<std::uint32_t>
	{
		std::vector<std::uint32_t> jobs;

		std::uint32_t job_start = proc->read<std::uint32_t>( this->task_scheduler + 0x134 );
		std::uint32_t job_end = proc->read<std::uint32_t>( this->task_scheduler + 0x138 );

		for (job_end; job_start != job_end; job_start += 8)
			jobs.push_back( proc->read<std::uint32_t>( job_start ) );

		return jobs;
	}

	auto task_scheduler::get_job( const std::string_view& name ) -> std::uint32_t
	{
		for (std::uint32_t job : this->jobs)
			if (name == proc->read_str( job + 0x10 ))
				return job;

		return 0;
	}

	auto task_scheduler::get_datamodel( ) -> std::uint32_t
	{
		return proc->read<std::uint32_t>( proc->read<std::uint32_t>( this->render + 0x28 ) + 8 );
	}

	auto task_scheduler::get_visual_engine( ) -> std::uint32_t
	{
		return proc->read<std::uint32_t>( proc->read<std::uint32_t>( this->render + 0x148 ) + 8 );
	}

	task_scheduler scheduler;
}