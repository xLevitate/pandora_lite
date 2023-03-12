#include "globals.hpp"

rbx::datamodel globals_t::datamodel = 0;
rbx::visualengine globals_t::visualengine = 0;
rbx::instance globals_t::workspace = 0;
rbx::players globals_t::players = 0;
rbx::player globals_t::local_player = 0;

std::vector<rbx::player> globals_t::player_list = {};