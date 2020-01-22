#include "GraphicsSystem.h"

sf::RenderWindow * GraphicsSystem::window = nullptr;

// This function is the default constructor
GraphicsSystem::GraphicsSystem()
{

}





// This function is the destructor
GraphicsSystem::~GraphicsSystem()
{

}





// This function initializes the display window with a 
// given width and height from the user
void GraphicsSystem::init(float width, float height)
{

	window = new sf::RenderWindow;
	window->create(sf::VideoMode((int)width, (int)height), "My window");

	window->clear(sf::Color::White);
}





// This function initializes the display window with a 
// given width and height from the user
void GraphicsSystem::init(sf::Sprite* sprite, float width, float height)
{

	window = new sf::RenderWindow;
	window->create(sf::VideoMode((int)width, (int)height), "My window");

	mBackBuffer = new GraphicsBuffer(sprite, "Backbuffer");
	window->draw(*mBackBuffer->getSprite());
}





// This function initializes the static instance of the graphics system
void GraphicsSystem::initStaticInstance()
{
	window = new sf::RenderWindow;
}





// This function cleans up and deletes the display
void GraphicsSystem::cleanup()
{
	window->close();
	delete window;
}





// This accesor function gets the height
float GraphicsSystem::getHeight()
{
	return (float)window->getSize().y;
}





// This accesor function gets the width
float GraphicsSystem::getWidth()
{
	return (float)window->getSize().x;
}





// This accesor function gets the back buffer
GraphicsBuffer  GraphicsSystem::getBackBuffer()
{
	return *mBackBuffer;
}





// This funtion gets the static instance of the render window
sf::RenderWindow * GraphicsSystem::getStaticInstance()
{
	assert(window != nullptr);
	return window;
}





// This function flips the display
void GraphicsSystem::flip()
{
	window->display();
}





// This function draws a sprite to the current backbuffer / target bitmap and scales it appropriately
void GraphicsSystem::draw(Vector2 targetLoc, GraphicsBuffer & newBuffer, float scale)
{
	newBuffer.bitmap->setScale(scale, scale);
	newBuffer.bitmap->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	window->draw(*newBuffer.bitmap);
}





// This function draws a sprite to a chosen buffer and scales it appropriately
void GraphicsSystem::draw(GraphicsBuffer& targetGraphicsBuffer, Sprite& sprite, float scale)
{
	window->draw(*targetGraphicsBuffer.getSprite());
}





// This function draws the background of a given buffer and scale
void GraphicsSystem::drawBackground(GraphicsBuffer& buffer, float scale)
{
	window->draw(*buffer.getSprite());
}





// This function draws a sprite from a given sprite sheet and places and scales it in a specific location
void GraphicsSystem::drawFromSpriteSheet(Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer& newBuffer, Vector2 scale)
{
	window->draw(*newBuffer.bitmap);
}





// This function draws a sprite from a given sprite sheet and places and scales it in a specific location, 
// it is a static variable such that it can be called from animation to split up the sprite sheet
void GraphicsSystem::drawFromSpriteSheet(GraphicsBuffer& targetGraphicsBuffer, Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer& sprite, Vector2 scale)
{
	int val = 0;

	targetGraphicsBuffer.getSprite()->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	targetGraphicsBuffer.getSprite()->setTextureRect(sf::IntRect(0, 0, sprite.getWidth(), sprite.getHeight()));
	window->draw(*targetGraphicsBuffer.getSprite());
}





// This function draws a sprite from a given graphics buffer, a given row, a given target image location,
// target location to draw at, the sprite, and the scale
void GraphicsSystem::drawFromSpriteSheet(GraphicsBuffer & targetGraphicsBuffer, int row, Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer & sprite, Vector2 scale)
{
	targetGraphicsBuffer.getSprite()->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	targetGraphicsBuffer.getSprite()->setTextureRect(sf::IntRect(0, 0, sprite.getWidth() / row, sprite.getHeight()));
	window->draw(*targetGraphicsBuffer.getSprite());
}





// This function draws text to a target location with a font, color, and message to the current graphics buffer / bitmaps
void GraphicsSystem::drawText(sf::Text mText)
{
	window->draw(mText);
}





// This function closes the display window after a certain amount of time,
// which is given by the user
void GraphicsSystem::closeWindow(float secondsDelay)
{
	cleanup();
}