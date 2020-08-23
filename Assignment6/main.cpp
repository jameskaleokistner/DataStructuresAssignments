#include "menu.h"

using namespace std;

int main(int args, char** input)
{
	//Error checking to make sure that only one file was enetered as command line
	bool run = true;
	if (input[1] == NULL)
	{
		cout << "No text file entered!" << endl;
		run = false;
	}
	else if (input[2] != NULL)
	{
		cout << "Too many text files entered!" << endl;
		run = false;
	}

	string newFile;
	if(!run)
	{
		cout << "Please enter ONE text file: " << flush;
		cin >> newFile;

	}
	else
	{
		newFile = input[1];
	}

	//Start of whole program
	Menu menu(newFile);
	menu.run();
	return 0;
}