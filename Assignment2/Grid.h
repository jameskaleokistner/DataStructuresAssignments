#ifndef Grid_H_
	#include "FileInput.h"
	#include <iostream>
	#include <fstream>
	#include <cmath>
	#include <math.h>
	#include <thread>
	#include <chrono>
	using namespace std;
#define Grid_H_
class Grid
{
public:
	Grid();
	Grid(int rows, int columns);
	Grid(const Grid &grid);
	~Grid();

	void copyFuture();
	void print();
	string printFile();
	void random(float density);
	void generateGrid(string line, int count);
	bool isInfinite();


	char** currentArray;
	char** futureArray;
	int rows;
	int columns;
	bool infinite;

private:
};

#endif
