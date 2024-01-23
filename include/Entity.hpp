#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos()
	{
		return pos;
	}
	Vector2f getScale()
	{
		return scale;
	}

	void setPos(float x, float y);

	void setScale(float w, float h);

	SDL_Texture* getTex();

	void update(double deltaTime);

	SDL_Rect getCurrentFrame();

	void render(SDL_Renderer* renderer);
	
private:
	Vector2f pos;
	float angle = 0;
	Vector2f scale = Vector2f(1, 1);
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};