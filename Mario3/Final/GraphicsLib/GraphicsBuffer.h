#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>

#include <iostream>
#include <cassert>
#include <string>
#include <stdlib.h>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include "Color.h"
#include "Vector2.h"

using namespace std;


class GraphicsBuffer : public Trackable
{
public:


	// Friends
	friend class GraphicsSystem;
	friend class Sprite;
	friend class GraphicsBufferManager;
	friend class Game;

	// Constructors
	GraphicsBuffer();
	GraphicsBuffer(string bitmapFilePath, string name);
	GraphicsBuffer(sf::Sprite* newMap, string name);
	GraphicsBuffer(int length, int height, Colors colorOfScreen, string name);
	GraphicsBuffer(int length, int height, string name);
	GraphicsBuffer(sf::Sprite* newMap, int length, int height, string name);
	GraphicsBuffer(sf::Texture* newText, int length, int height, string name);

	// Destructors
	~GraphicsBuffer();

	// Acessor Functions
	int getHeight();
	int getWidth();

	// Mutators
	void setIntRect(int xCoordinate, int yCoordinate, int width, int height);
	void setBitmapPosX(int xMod);
	void setBitmapPosY(int modY);

	void setBitmapPosToPlayerX(int xMod);

private:

	sf::Sprite* getSprite() { return bitmap; };

	bool mIsBackBuffer;

	string mName;

	Vector2 *mBitmapPos;

	sf::Texture* texture;
	sf::Sprite* bitmap;
};

#endif