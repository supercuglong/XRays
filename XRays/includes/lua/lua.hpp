// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

#pragma once

extern "C" {
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}
