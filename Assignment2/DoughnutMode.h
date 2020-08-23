#ifndef DoughnutMode_H_
	#include <iostream>
	#include <fstream>
	#include <cmath>
	#include <math.h>
	#include "Grid.h"
	using namespace std;
#define DoughnutMode_H_
class DoughnutMode
{
public:
	DoughnutMode(string input);
	DoughnutMode(float density);
	~DoughnutMode();
	void run(char pause);
	int checkGrid(int row, int column);
	void fate(int pop, int row, int column);
private:
	Grid* grid;
};

#endif