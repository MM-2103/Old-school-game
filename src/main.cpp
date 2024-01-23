#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Utils.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Tile.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("GAME v1.0", 1280, 480);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/abandoned-mine.png");
	SDL_Texture* backgroundTexture = window.loadTexture("res/gfx/background.png");

    std::vector<Tile> platforms = 
    {
       	Tile(Vector2f(0, 0), grassTexture),
	   	Tile(Vector2f(30, 0), grassTexture),
       	Tile(Vector2f(30, 30), grassTexture),
       	Tile(Vector2f(40, 60), grassTexture)
   	};

	{

	    Tile platformB(Vector2f(100, 50), grassTexture);
	    platforms.push_back(platformB);
	}
	
	bool gameRunning = true;

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds(); 

// Game loop 
	while (gameRunning)
	{
		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while(accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					gameRunning = false;
				}
			}

			accumulator -= timeStep;
		}

		// const float alpha = accumulator / timeStep;

		window.clear();

    	window.render(0, 0, backgroundTexture);

        for (Entity& e : platforms)
        {
            window.render(e);
        }

		window.display();

		std::cout << utils::hireTimeInSeconds() << std::endl;
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}