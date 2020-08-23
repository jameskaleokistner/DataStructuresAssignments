#ifndef MirrorMode_H_
	#include <iostream>
	#include <fstream>
	#include <cmath>
	#include <math.h>
	#include "Grid.h"
	using namespace std;
#define MirrorMode_H_
class MirrorMode
{
public:
	MirrorMode(string input);
	MirrorMode(float density);
	~MirrorMode();
	void run(char pause);
	int checkGrid(int row, int column);
	void fate(int pop, int row, int column);
private:
	Grid* grid;
};

#endif