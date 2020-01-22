#ifndef COLORS_H
#define COLORS_H

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

using namespace std;

class Colors : public Trackable
{
public:


	// Friends
	friend class GraphicsBuffer;
	friend class GraphicsSystem;
	friend class Text;

	// Constructors
	Colors();
	Colors(float r, float g, float b);
	Colors(float r, float g, float b, float a);

	// Destructor
	~Colors();

	// Mutators
	void setR(float newR);
	void setG(float newG);
	void setB(float newB);

	// Accessors
	float getR() { return mCurrentColor.r; }
	float getG() { return mCurrentColor.g; }
	float getB() { return mCurrentColor.b; }

private:
	//Colors
	sf::Color mCurrentColor;
};

#endif