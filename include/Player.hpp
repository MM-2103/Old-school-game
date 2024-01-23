#pragma once

class player
{
public:
	Player();
	void moveRight();
	void moveLeft();
	void jump();
	void update(); // To update player state each frame
	void render(); // To draw the player on the screen
private:
	int x, y;
	int velocityX, velocityY;
	int width, height;
};