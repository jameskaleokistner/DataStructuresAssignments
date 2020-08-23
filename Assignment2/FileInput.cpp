#include "FileInput.h"

void FileInput::openFile(string name)
{
	this->inputFile.open(name);
	while (this->inputFile.is_open() == false)
    {
    	cout << "\nFile does not exist!" << endl;
    	cout << "Please enter a file that exists or type 'exit': " << flush;
    	cin >> name;
    	if (name == "exit")
    	{
    		cout << "Exiting Program..." << endl;
    		exit(0);
    	}
    	this->inputFile.open(name);
 	}
 	cout << "The text file being read is: " << name << endl;
}

void FileInput::closeFile()
{
	this->inputFile.close();
}

