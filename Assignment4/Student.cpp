#include "Student.h"

Student::Student(int waitTime, int timeInQueue)
{
	this->waitTime = waitTime;
	this->timeInQueue = timeInQueue;
}

Student::~Student()
{
	cout << "Student Deleted" << endl;
}

void Student::printTimeInQueue()
{
	cout << this->timeInQueue << endl;
}