#include "lua.hpp"
#include "GameObject.h"

GameObject::GameObject() {
	if (script.is_active()) {
		set_script(script);
	}
};

void GameObject::set_script(Script& scr) {
	if (this->lua_state != NULL) {
		lua_close(this->lua_state);
		this->lua_state = NULL;
	}
	this->lua_state = lua_newstate(NULL, NULL);
	luaL_dostring(this->lua_state, scr.code);
}