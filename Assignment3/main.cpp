#include "Syntax.h"

int main(int args, char** clInput)
{
	//String used to track user input throughout program
	bool run = true;
	int count = 0;
	string input;
	//If statement to check if command line is null, or if more than one text file is enetered
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

	//Setting input equal to the text file the user entered
	else
	{
		input = clInput[1];
	}

	//While loop to check for multiple files
	while (run)
	{
		Syntax syntax(input);
		syntax.run();

		char c;
		cout << "If you would you like to check another file type (y): " << flush;
		cin >> c;
		c = toupper(c);

		if(c == 'Y')
		{
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
			run = false;
		}
	}
	return 0;
}
