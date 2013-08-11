#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "entity.hpp"

// STL -libstdc++
#include <memory>

// Forward declarations
struct SDL_Texture;

namespace bomberman {
namespace architecture {

	class Block;
	typedef std::shared_ptr<Block> BlockPtr;

	class Block : public Entity {
		public:
			enum Type {
				Floor,
				Obstacle
			};

			static BlockPtr Create(Type iType);
			virtual void Render(SDL_Renderer* iRenderer) const;
		
		protected:
			Type _type;

			static void InitializeGraphicRessources(SDL_Renderer *iRenderer);
			static std::shared_ptr<SDL_Texture> _Block, _Floortile;
	};
}
}

#endif