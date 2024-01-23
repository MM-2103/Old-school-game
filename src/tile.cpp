#include "Tile.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include <SDL2/SDL.h>


Tile::Tile(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex)
{
}