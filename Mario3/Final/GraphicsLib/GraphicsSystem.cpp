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

	window->clear(sf::Color(255, 255, 255, 0));
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
void GraphicsSystem::draw(Vector2 targetLoc, Sprite& sprite, float scale)
{
	sprite.getGraphicsBuffer()->bitmap->setScale(scale, scale);
	sprite.getGraphicsBuffer()->bitmap->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	window->draw(*sprite.getGraphicsBuffer()->bitmap);
}





// This function draws a sprite to a chosen buffer and scales it appropriately
void GraphicsSystem::draw(GraphicsBuffer& targetGraphicsBuffer, Sprite& sprite, float scale)
{
	window->draw(*targetGraphicsBuffer.getSprite());
}





void GraphicsSystem::drawBackground(GraphicsBuffer& buffer, float scale)
{
	window->draw(*buffer.getSprite());
}





// This function draws a sprite from a given sprite sheet and places and scales it in a specific location
void GraphicsSystem::drawFromSpriteSheet(Vector2 targetImageLoc, Vector2 targetLoc, Sprite& sprite, Vector2 scale)
{
	window->draw(*sprite.getGraphicsBuffer()->getSprite());
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

void GraphicsSystem::drawFromSpriteSheet(GraphicsBuffer & targetGraphicsBuffer, int row, Vector2 targetImageLoc, Vector2 targetLoc, GraphicsBuffer & sprite, Vector2 scale)
{
	targetGraphicsBuffer.getSprite()->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	targetGraphicsBuffer.getSprite()->setTextureRect(sf::IntRect(0, 0, sprite.getWidth() / row, sprite.getHeight()));
	window->draw(*targetGraphicsBuffer.getSprite());
}

void GraphicsSystem::drawFromSpriteSheet(GraphicsBuffer & targetGraphicsBuffer, int row, Vector2 targetImageLoc, Vector2 targetLoc, Sprite & sprite, Vector2 scale)
{
	targetGraphicsBuffer.getSprite()->setPosition((float)targetLoc.mX, (float)targetLoc.mY);
	window->draw(*targetGraphicsBuffer.getSprite());
}





// This function draws text to a target location with a font, color, and message to the current graphics buffer / bitmaps
void GraphicsSystem::drawText(sf::Text * text)
{
	window->draw(*text);
}





// This function saves a given graphics buffer to as a file, whose name is determined by the user
void GraphicsSystem::saveBuffer(GraphicsBuffer& bufferToSave, string fileName)
{
	//bufferToSave.getTexture()->copyToImage().saveToFile() getTexture()->copyToImage.saveToFile(fileName);
}





// This function closes the display window after a certain amount of time,
// which is given by the user
void GraphicsSystem::closeWindow(float secondsDelay)
{
	cleanup();
}