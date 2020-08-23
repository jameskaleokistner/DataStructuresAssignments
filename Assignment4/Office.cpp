#include "Office.h"

Office::Office(string file)
{
	this->fileName = file;
	this->meanStudent = 0.0;
	this->medianStudent = 0.0;
	this->maxStudentWait = 0.0;
	this->numStudents10 = 0;
	this->meanWindow = 0.0;
	this->maxWindowWait = 0.0;
	this->numWindows5 = 0;
	myQueue = new Queue<Student>();
}

Office::~Office()
{
	cout << "Office object deleted" << endl;
}

void Office::runSim()
{
	FileInput iFile;
	iFile.openFile(this->fileName);
	int fLine;

	bool line1 = true;
	bool readStudents = false;
	bool readWaitTimes = false;
	bool readClockTick = false;

	int windowsOpen = 0;
	int numStudents = -1;
	int checkNumStudents = 0;
	int timePeriod = 0;
	int count = 0;

	iFile.inputFile >> fLine;
	windowsOpen = fLine;
	readClockTick = true;
	Window* windows;

	for(int i = 0; i < fLine; i++)
	{
		windows = new Window(windowsOpen);
	}


	while(iFile.inputFile >> fLine)
	{
		if (numStudents == checkNumStudents)
		{
			numStudents = -1;
			checkNumStudents = 0;
			//cout << "\n5" << endl;
			//cout << fLine << endl;
			readWaitTimes = false;
			readClockTick = true;
		}

		if (readClockTick)
		{
			//cout << "\n2" << endl;
			//cout << fLine << endl;
			timePeriod = fLine;
			count++;
			if (count != timePeriod)
			{
				while(count != timePeriod)
				{
					windows->clockTick();
					count++;
				}
			}
			else
			{
				windows->clockTick();
			}
			readClockTick = false;
			readStudents = true;
		}

		else if (readStudents)
		{
			//cout << "\n3" << endl;
			//cout << fLine << endl;
			numStudents = fLine;
			readStudents = false;
			readWaitTimes = true;
		}

		else if (readWaitTimes)
		{
			//cout << "\n4" << endl;
			//cout << fLine << endl;
			Student iStudent(fLine, timePeriod);
			myQueue->insert(iStudent);
			int check = windows->isOpen();
			if (check != -1)
			{
				Student rStudent = myQueue->remove();
				windows->fill(check, rStudent);
			}
			checkNumStudents++;
		}

		windows->checkWindows();
	}
	//myQueue->printQueue();
	iFile.closeFile();
	delete myQueue;
	delete windows;
}

/*	Queue<T> *myQueue = new Queue<char>();
	myQueue->insert('a');
	myQueue->printQueue();*/