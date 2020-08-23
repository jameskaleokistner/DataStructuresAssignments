#include "Grid.h"
#include "FileInput.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"
#include <ctype.h>

int main()
{
	//Initializing variables to be used throughout program for user input
	char output;
	string input;
	char file;
	char gameMode;

	//Error Checking user input
	while(true)
	{
		cout << "Would you like to provide a file for the Game of Life? (Y/N): " << flush;
		cin >> file;
		file = toupper(file);
		if (file == 'Y' || file == 'N')
		{
			break;
		}
		cout << "Please enter a valid response!" << endl;
	}


	//Error Checking user input
	cout << "Which game mode would you like to play? The availible game modes are:\n\tClassic mode\n\tDoughnut Mode\n\tMirror mode\nPlease enter (C, D, or M): " << flush;
	cin >> gameMode;
	gameMode = toupper(gameMode);
	bool gm = true;
	while (gm)
	{
		if (gameMode == 'C' || gameMode == 'D' || gameMode == 'M')
		{
			gm = false;
		}
		else
		{
			cout << "Please enter a valid game mode Classic, Doughnut, or Mirror (C, D, or M): " << flush;
			cin >> gameMode;
			gameMode = toupper(gameMode);
		}
	}

	//Error Checking user input
	cout << "Would you like to output between generations, hit enter between generations, or output results to a file (P/E/O): " << flush;
	cin >> output;
	output = toupper(output);
	while (true)
	{
		if ((output != 'P') && (output != 'E') && (output != 'O'))
		{
			cout << "Please type 'P' to output between generations, 'E' to hit enter between generations or 'O' to output results to a file: " << flush;
			cin >> output;
			output = toupper(output);
		}
		else
		{
			break;
		}

	}


	//If statement that is fufilled if user wants to read from a file
	if (file == 'Y')
	{
		cout << "Please enter the text file to be read from: " << flush;
		cin >> input;

			//Opening file
		FileInput file;
		file.openFile(input);

	    string line;
	    int count = 0;
	    int rows;
	    int columns;

	    //Reading rows and columns from file
	   	for (int i = 0; i < 2; i++)
	   	{
	   		file.inputFile >> line;
	   		if (isdigit(line[0]) && count == 0)
			{
				rows = line[0] - 48;
				count++;
			}

			else if (isdigit(line[0]) && count == 1)
		   	{
		   		columns = line[0] - 48;
		   	}

	   	}

	   	//Creating a grid class object using rows and columns that were read in from a file
	   	Grid grid = Grid(rows, columns);
	   	count = 0;
	   	while (file.inputFile >> line)
	   	{
	   		//Generates grid based on lines and count
	   		grid.generateGrid(line, count);
	   		count++;
	   	}

	   	//closes input file	
	    file.closeFile();
	   	
	   	//Checks to see what gamemode was selected
	   	if (gameMode == 'C')
	   	{
	   		ClassicMode classic = ClassicMode(input);
	   		//runs game 
	   		classic.run(output);
	   	}

	   	else if (gameMode == 'D')
	   	{
	   		DoughnutMode doughnut = DoughnutMode(input);
	   		//runs game
	   		doughnut.run(output);
	   	}

	   	else if (gameMode == 'M')
	   	{
	   		MirrorMode mirror = MirrorMode(input);
	   		//runs game
	   		mirror.run(output);
	   	}

	}

	//If statement fufilled if user wants radnomly generated grid based on given density
	else if (file == 'N')
	{
		float density;
		cout << "Please enter a number between 0 and 1 for the initial population density: " << flush;
		cin >> density;

		//Error checking density input
		while (density <= 0 || density >= 1)
		{
			cout << "Please enter a number between 0 and 1: " << flush;
			cin >> density;
		}
		//generates grid based on density

		//Checks what game mode the user selected
		if (gameMode == 'C')
	   	{
	   		ClassicMode classic = ClassicMode(density);
	   		//runs game
	   		classic.run(output);
	   	}

	   	else if (gameMode == 'D')
	   	{
	   		DoughnutMode doughnut = DoughnutMode(density);
	   		//runs game
	   		doughnut.run(output);
	   	}

	   	else if (gameMode == 'M')
	   	{
	   		MirrorMode mirror = MirrorMode(density);
	   		//runs game
	   		mirror.run(output);
	   	}

	}

	return 0;
}
