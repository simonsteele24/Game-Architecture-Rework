#include "GraphicsBuffer.h"

// This is the default constuctor for the class
GraphicsBuffer::GraphicsBuffer()
{
	// Intiailize bitmap to a null value
	mIsBackBuffer = false;
	bitmap = NULL;
	texture = NULL;
}





// This constuctor takes the stored bitmap based 
// on an asset file path
GraphicsBuffer::GraphicsBuffer(string bitmapFilePath, string name)
{
	mName = name;
	mIsBackBuffer = false;

	texture = new sf::Texture;
	bitmap = new sf::Sprite;

	if (!texture->loadFromFile(bitmapFilePath))
	{
		//error
	}

	bitmap->setTexture(*texture);
}

GraphicsBuffer::GraphicsBuffer(sf::Sprite* newMap, string name)
{
	texture = new sf::Texture;
	bitmap = new sf::Sprite;
	mName = name;
	mIsBackBuffer = true;
	bitmap = newMap;
}





// This constructor takes the width and height and also the
// color to create a colored bitmap
GraphicsBuffer::GraphicsBuffer(int width, int height, Colors colorOfScreen, string name)
{
	mName = name;

	mIsBackBuffer = false;
}





// This constructor creates a blank bitmap from only a given
// length and height
GraphicsBuffer::GraphicsBuffer(int length, int height, string name)
{
	mName = name;
	mIsBackBuffer = false;
	texture = new sf::Texture;
	bitmap = new sf::Sprite;

	texture->create(length, height);
	bitmap->setTexture(*texture);
}

GraphicsBuffer::GraphicsBuffer(sf::Sprite * newMap, int length, int height, string name)
{
	mName = name;
	mIsBackBuffer = false;
	texture = new sf::Texture;
	bitmap = new sf::Sprite;

	texture->create(length, height);
	bitmap->setTexture(*texture);

	bitmap = newMap;
}

GraphicsBuffer::GraphicsBuffer(sf::Texture * newText, int length, int height, string name)
{
	mName = name;
	mIsBackBuffer = false;
	texture = newText;
	bitmap = new sf::Sprite;

	bitmap->setTexture(*texture);
}





// This function gets the height of the stored bitmap
int GraphicsBuffer::getHeight()
{
	return texture->getSize().y;
}





// This function gets the width of the stored bitmap
int GraphicsBuffer::getWidth()
{
	return texture->getSize().x;
}





// This function destroys the stored allegro bitmap
GraphicsBuffer::~GraphicsBuffer()
{
}





// This function sets the int-rect of a sprite sheet to a certain value
void GraphicsBuffer::setIntRect(int xCoordinate, int yCoordinate, int width, int height)
{
	bitmap->setTextureRect(sf::IntRect(xCoordinate, yCoordinate, width, height));
}





void GraphicsBuffer::setBitmapPosX(int xMod) 
{
	//mBitmapPos->mX += xMod;
}





void GraphicsBuffer::setBitmapPosY(int modY)
{
	///mBitmapPos->mY += modY;
}





void GraphicsBuffer::setBitmapPosToPlayerX(int xMod) 
{
	//mBitmapPos->mX = xMod;
}