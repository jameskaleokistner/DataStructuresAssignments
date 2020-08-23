#ifndef ClassicMode_H_
	#include <iostream>
	#include <fstream>
	#include <cmath>
	#include <math.h>
	#include "Grid.h"
	using namespace std;
#define ClassicMode_H_
class ClassicMode
{
public:
	ClassicMode(string input);
	ClassicMode(float density);
	~ClassicMode();
	void run(char pause);
	int checkGrid(int row, int column);
	void fate(int pop, int row, int column);
private:
	Grid* grid;
};

#endif