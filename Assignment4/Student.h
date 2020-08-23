#ifndef Student_H_
	#include <iostream>
	using namespace std;
#define Student_H_
class Student
{
	public:
		Student(int waitTime, int timeInQueue);
		~Student();

		void printTimeInQueue();
		int waitTime;

	private:

		int timeInQueue;
};
#endif