#pragma once
#include "lua.hpp"
#include "Core/GameObject/Script.h"
#include "Core/UString.h"

class GameObject
{
public :
	lua_State* lua_state = nullptr;
	Script script;

	GameObject();

	void set_script(Script &scr);

};

