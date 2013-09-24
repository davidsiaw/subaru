#include "computer.hpp"

namespace bomberman {
namespace bestiary {
	ComputerPtr Computer::Create(const std::string &iName, const std::string &iSpriteName, int iInputStateIdx, SDL_Renderer* iRenderer, bool* alive)
	{
		SDL_RWops *rw = SDL_RWFromFile("aiscripts/example.lua", "r");

		auto size = rw->size(rw);
		char* script = new char[size];
		rw->read(rw, script, sizeof(char), size);
		
		SDL_FreeRW(rw);

		ScriptAPI sa(script);

		auto player = std::make_shared<Computer>(sa);
		player->_name = iName;
		player->_spriteName = iSpriteName;
		player->zlevel = 2;
		player->_frameId = 3;
		player->_nextFrameDueTime = 0;
		player->_nextUpdateDueTime = 0;
		player->_state = IdleDown;
		player->_inputStateIdx = iInputStateIdx;
		player->InitializeGraphicRessources(iRenderer);
		player->_alive = alive;

		delete[] script;

		return player;
	}

	Computer::Computer(ScriptAPI script) : 
		_script(script)
	{
	}

	void Computer::Evolve(const std::vector<InputState>& /* iInputs */, uint32_t iTimestamp, const MapConstPtr &iPresentMap, const MapPtr &iFutureMap) const
	{
		std::vector<InputState> inputs(4);
		inputs[_inputStateIdx] = _script.Resume(x, y, iPresentMap);

		Player::Evolve(inputs, iTimestamp, iPresentMap, iFutureMap);
	}

	void Computer::Interact(const std::vector<InputState>& iInputs, uint32_t iTimestamp, const EntitySet &iEntities)
	{
		Player::Interact(iInputs, iTimestamp, iEntities);
	}
}
}
