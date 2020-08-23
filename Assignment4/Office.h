#ifndef Office_H_
	#include <iostream>
	#include "FileInput.h"
	#include "GenQueue.cpp"
	#include "Student.h"
	#include "Window.h"
#define Office_H_
class Office
{
public:
	Office(string file);
	~Office();

	void runSim();


private:
	string fileName;
	float meanStudent;
	float medianStudent;
	float maxStudentWait;
	int numStudents10;
	float meanWindow;
	float maxWindowWait;
	int numWindows5;
	Queue<Student> *myQueue;
};
#endif