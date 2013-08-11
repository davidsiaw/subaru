#ifndef TESTSCENE_HPP
#define TESTSCENE_HPP

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <list>
#include "scene_interface.hpp"
#include "map.hpp"
#include "touchscreenkeyscene.hpp"

namespace bomberman {

class TestScene : public SceneInterface
{
	struct BombInfo
	{
		int timeout;
		int strength;
	};

	struct ExplosionInfo
	{
		int x,y;
		int timeout;
		int stage;
	};

	Map map;
	EntityPtr player;
	EntityPtr computer;
	TouchScreenKeyScene keys;
	
	std::shared_ptr<SDL_Texture> block;
	std::shared_ptr<SDL_Texture> bomb;
	std::shared_ptr<SDL_Texture> bomberman;
	std::shared_ptr<SDL_Texture> bombergirl;
	std::shared_ptr<SDL_Texture> floortile;

	std::shared_ptr<SDL_Texture> explosionSprite[4];
	
	typedef std::pair<EntityPtr,BombInfo> bombInfoPair;
	
	std::list<ExplosionInfo> explosions;
	std::list<bombInfoPair> bombs;
	std::list<EntityPtr> overlappingBombs;



public:
	TestScene();
	virtual ~TestScene();
	virtual void Init(SDL_Window* window, SDL_Renderer* renderer);
	virtual void Update(const InputState& inputs, Uint32 timestamp);
	virtual void Render(SDL_Renderer *renderer);
	virtual bool Running();
};

}

#endif // TESTSCENE_HPP
