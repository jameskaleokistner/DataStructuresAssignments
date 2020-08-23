#include "Office.h"

int main(int args, char** clInput)
{
	string input;

	if (clInput[1] == NULL || clInput[2] != NULL)
	{
		cout << "No text file entered, or more than one text file entered!" << endl;
		cout << "Please enter a single text file or type 'exit': " << flush;
		cin >> input;
		if (input == "exit")
		{
			cout << "Exiting Program..." << endl;
			exit(0);
		}
	}
	else
	{
		input = clInput[1];
	}

	Office office(input);
	office.runSim();

	return 0;
	/*Queue<Student*>* myQueue = new Queue<Student*>();
	Student* student = new Student(5, 4);
	myQueue->insert(student);
	Student* stud2 = myQueue->remove();
	stud2->printTimeInQueue();

	delete student;

	return 0;*/


}