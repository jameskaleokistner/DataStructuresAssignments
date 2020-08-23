#include "A1.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int args, char** clInput) 
{
	//Opening the file I will write to later in the program and adding a header each time the program is run
	ofstream outputFile;
	outputFile.open ("jameskistner.txt", ios_base::app);
	outputFile << "James Kistner \n" << "2289293 \n" << "CPSC350" << endl;

	//Variables used to calculate mean, variance, standard deviation, and string length
	int countLines = 0;
	int countLength = 0;
	float variance = 0;
	float sd = 0;


	while (true) 
	{
		bool file = true;
		//String used to track user input throughout program
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
			if (file == true)
			{
				input = clInput[1];
			}
			
		}

		//Creating input file stream
		ifstream inputFile;
		inputFile.open(input);

		//While loop checking to see if the file exists and can be read from. Only breaks if a valid file is entered, or the user exits
	    while (inputFile.is_open() == false)
	    {
	    	cout << "File does not exist!" << endl;
	    	cout << "Please enter a file that exists or type 'exit': " << flush;
	    	cin >> input;
	    	if (input == "exit")
	    	{
	    		cout << "Exiting Program..." << endl;
	    		exit(0);
	    	}
	    	inputFile.open(input);
	    }

	   	cout << "The text file being read is: " << input << endl;

	   	//String used to store data read in from the file
	   	string fLine;
	   	//While loop that goes through each line and creates statistics about the nucleotides
	   	while (inputFile >> fLine)
	   	{
	   		//Method that deals with individual characters of the dna string
			DNA::nukeCount(fLine);
			//Find length of string	   		
	   		int len = DNA::lineLength(fLine);
	   		//Prints out the line being read and length of the line
	   		cout << len << endl;
	   		cout << fLine << endl;
	   		countLines++;
	   		countLength += len;
	   	}

	   	//Displays the stats about nucleotides
	   	string nukes = DNA::getNukes();
	   	cout << nukes << endl;

	   	//Goes back to the top of file being read
	   	inputFile.clear();
		inputFile.seekg(0, inputFile.beg);

		//Calculates the mean
		float mean = float(countLength)/float(countLines);
	   	mean = roundf(mean * 100) / 100;

	   	//While loop to read from the same text file again
	   	while (inputFile >> fLine)
	   	{
	   		//Methods used to collect data for variance and line length
	   		int len = DNA::lineLength(fLine);
	   		int var = DNA::varianceSquare(mean, len);
	   		variance += var;
	   	}

	   	//Calculating variance
	   	variance = DNA::variance(variance, countLines);
	   	variance = roundf(variance * 100) / 100;
	   	//Calculating standard deviation
	   	sd = sqrt(variance);
	   	sd = roundf(sd * 100) / 100;


	   	//Printing results
	   	cout << "\n" << "There were " << countLines << " strings of DNA" <<  "\n" << endl;
	   	cout << "Sum of neucleotides: " << countLength << endl;
	   	cout << "Mean of DNA strings: " << mean << endl;
	   	cout << "The variance of the data is: " << variance << endl;
	   	cout << "The standard deviation of the data is: " << sd << endl;

	 //For loop creating 1000 strings to append
	   	for (int i = 0; i < 1000; i++)
	   	{
	   		//string to append
	   		string newLine;
	   		//int that finds a random string length
	   		int stringL = DNA::gaussin(mean, sd);

	   		//for loop to find probability of nucleotide and append it to a string
	   		for (int i = 0; i < stringL; i++)
	   		{
	   			string add = DNA::getChar();
	   			newLine += add;
	   		}

	   		//writes string to output file
	   		outputFile << newLine << endl;
	   	}

		//Closes current files	
	   	inputFile.close();


	   	//Checking to see if user has another file
	   	char c;
	   	cout << "Would you like to enter another file? (Y/N): " << flush;
	   	cin >> c;
	   	c = toupper(c);
	   	if (c == 'N')
	   	{
	   		//Exit condition
	   		cout << "Exiting program..." << endl;
	   		break;
	   	}

	   	else
	   	{
	   		//Reseting variables so fresh text file can be used
	   		cout << "Please enter the text file name: " << flush;
	   		cin >> input;
	   		countLines = 0;
	   		countLength = 0;
	   		variance = 0;
	   		sd = 0;
	   		file = false;
	   		DNA::resetNukes();

	   	}

	}
	outputFile.close(); 


  
    return 0; 
} 