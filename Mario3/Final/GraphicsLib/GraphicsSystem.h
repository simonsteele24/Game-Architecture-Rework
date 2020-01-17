#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

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

#include "GraphicsBuffer.h"
#include "Font.h"
#include "Color.h"
#include "Sprite.h"

using namespace std;

class GraphicsSystem : public Trackable
{
public:


	// Constructors
	GraphicsSystem();


	// Destructors
	~GraphicsSystem();


	// Initializes / Deinitializers
	void init(float width, float height);
	void init(sf::Sprite* sprite, float width, float height);
	static void initStaticInstance();

	void cleanup();


	// Acessors
	float getHeight();
	float getWidth();
	GraphicsBuffer getBackBuffer();
	static sf::RenderWindow* getStaticInstance();

	// Display-controller functions
	void closeWindow(float secondsDelay);
	void flip();

	// Drawing functions for sprites
	void draw(Vector2 targetLoc, GraphicsBuffer & newBuffer, float scale);
	void drawBackground(GraphicsBuffer& buffer, float scale);
	void draw(GraphicsBuffer& targetGraphicsBuffer, Sprite& sprite, float scale);


	// Drawing functions for sprite sheets
	void drawFromSpriteSheet(Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer& newBuffer, Vector2 scale);
	static void drawFromSpriteSheet(GraphicsBuffer& targetGraphicsBuffer, Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer& sprite, Vector2 scale);
	static void drawFromSpriteSheet(GraphicsBuffer& targetGraphicsBuffer, int row, Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer& sprite, Vector2 scale);
	static void drawFromSpriteSheet(GraphicsBuffer& targetGraphicsBuffer, int row, Vector2 targetImageLoc, Vector2 targetLoc, Sprite& sprite, Vector2 scale);

	// Drawing functions for text
	void drawText(Fonts font, Colors newColor, string newMessage, Vector2 newPosition, int fontSize, Colors fillColor);


	// Save/load functions
	void saveBuffer(GraphicsBuffer& bufferToSave, string fileName);


private:

	// Graphics Buffers
	GraphicsBuffer * mBackBuffer;

	sf::Text mTextObj;
	static sf::RenderWindow* window;
};

#endif