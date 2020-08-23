#ifndef Window_H_
	#include <iostream>
	using namespace std;
	#include "Student.h"
#define Window_H_
class Window
{
public:
	Window(int num);
	~Window();

	int isOpen();
	void fill(int index, Student iStudent);
	void checkWindows();
	void clockTick();

private:
	int numWindows;
	int* myArray;

};
#endif