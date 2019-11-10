#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <cassert>
#include <string>
#include <stdlib.h>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

using namespace std;


class Fonts : public Trackable
{
public:


	// Friends
	friend class GraphicsSystem;
	friend class Text;

	// Constructors
	Fonts();
	Fonts(string fontFilePath, int fontSize);
	Fonts(string fontFilePath);

	// Destructors
	~Fonts();

	// Accesors
	int getSize();

	// Mutators
	void setSize(int newSize);

private:

	// Strings
	string mFilePath;

	// Ints
	int mFontSize;

};

#endif