#include "DoughnutMode.h"

DoughnutMode::DoughnutMode(string input)
{
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
   	grid = new Grid(rows, columns);
   	count = 0;
   	while (file.inputFile >> line)
   	{
   		//Generates grid based on lines and count
   		grid->generateGrid(line, count);
   		count++;
   	}

   	file.closeFile();
}


DoughnutMode::DoughnutMode(float density)
{
	grid = new Grid();
	grid->random(density);
}

//Destructor
DoughnutMode::~DoughnutMode()
{
	delete grid;
	cout << "DoughnutMode Deleted" << endl;
}


///Main method of doughnut mode used to run this game mode
void DoughnutMode::run(char pause)
{
	//Creates general output file to be used based on user input of either pause or output results
	ofstream outFile;
	string outputString;
	if (pause == 'O')
	{
		//creates file
		string file;
		cout << "Please enter the file you wish to wrtie to: " << flush;
		cin >> file;
		outFile.open(file);
		outFile << "James Kistner \n" << "2289293 \n" << "CPSC350" << endl;
		outFile << outputString << endl;
	}

	int generation = 0;
	//While loop that goes through generations as long as it is infinite
	while(grid->infinite == true)
	{
		//goes through each box
		for (int i = 0; i < grid->rows; i++)
		{
			for (int j = 0; j < grid->columns; j++)
			{
				//checks surrounding pop
				int pop = DoughnutMode::checkGrid(i, j);
				//decides fate of box
				DoughnutMode::fate(pop, i, j);
			}

		}

		//Outputs generation and grid
		cout << "\nGeneration: " << generation << endl;
		grid->print();

		//prints to file if selected
		if (pause == 'O')
		{
			outFile << "\nGeneration: " << generation << endl;
			outputString = grid->printFile();
			outFile << outputString << endl;
		}

		//pauses if selected
		else if (pause == 'E')
		{
			cout << "Please hit ENTER to continue to the next generation: " << flush;
			cin.get();
			cin.get();
		}

		else if (pause == 'P')
		{
			this_thread::sleep_for (chrono::seconds(5));
		}

		bool infinite = grid->isInfinite();
		if (!infinite)
		{
			grid->infinite = false;
		}
		
		//copies future array to current array
		grid->copyFuture();
		generation++;
	}

	//closes file if selected
	if (pause == 'O')
	{
		outFile.close();
	}
}

//Method used to check each box surrounding a given box returns a count of the amount of neighbors
int DoughnutMode::checkGrid(int row, int column)
{
	int count = 0;
	//Right Middle Box

	if ((column + 1) < grid->columns)
	{
		if (grid->currentArray [row][column + 1] == 'X')
		{
			count++;
		}
	}

	else if ((column + 1) == grid->columns)
	{
		if (grid->currentArray [row][0] == 'X')
		{
			count++;
		}
	}

	//Left Middle Box
	if ((column - 1) >= 0)
	{
		if (grid->currentArray [row][column - 1] == 'X')
		{
			count++;
		}
	}
	else if ((column - 1) < 0)
	{
		if (grid->currentArray [row][grid->columns - 1] == 'X')
		{
			count++;
		}
	}

	//Bottom Left Box
	if ((row + 1) < grid->rows && (column - 1) >= 0)
	{
		if (grid->currentArray [row + 1][column - 1] == 'X')
		{
			count ++;
		}
	}

	else if ((row + 1) == grid->rows && (column -1) >= 0)
	{
		if (grid->currentArray [0][column - 1] == 'X')
		{
			count ++;
		}
	}

	else if ((row + 1) < grid->rows && (column -1) < 0)
	{
		if (grid->currentArray [row + 1][grid->columns - 1] == 'X')
		{
			count ++;
		}
	}

	else if ((row + 1) == grid->rows && (column -1) < 0)
	{
		if (grid->currentArray [0][grid->columns - 1] == 'X')
		{
			count ++;
		}
	}

	//Top Right Box
	if ((row - 1) >= 0 && (column + 1) < grid->columns)
	{
		if (grid->currentArray [row - 1][column + 1] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) < 0 && (column + 1) < grid->columns)
	{
		if (grid->currentArray [grid->rows - 1][column + 1] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) >= 0 && (column + 1) == grid->columns)
	{
		if (grid->currentArray [row - 1][0] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) < 0 && (column + 1) == grid->columns)
	{
		if (grid->currentArray [grid->rows - 1][0] == 'X')
		{
			count++;
		}
	}

	//Top Middle Box
	if ((row - 1) >= 0)
	{
		if (grid->currentArray [row - 1][column] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) < 0)
	{
		if (grid->currentArray [grid->rows - 1][column] == 'X')
		{
			count++;
		}
	}

	//Bottom Middle Box
	if ((row + 1) < grid->rows)
	{
		if (grid->currentArray [row + 1][column] == 'X')
		{
			count++;
		}
	}

	else if ((row + 1) == grid->rows)
	{
		if (grid->currentArray [0][column] == 'X')
		{
			count++;
		}
	}

	//Bottom Right Box
	if ((row + 1) <  grid->rows && (column + 1) < grid->columns)
	{
		if (grid->currentArray [row + 1][column + 1] == 'X')
		{
			count++;
		}
	}

	else if ((row + 1) == grid->rows && (column + 1) < grid->columns)
	{
		if (grid->currentArray [0][column + 1] == 'X')
		{
			count++;
		}
	}

	else if ((row + 1) < grid->rows && (column + 1) == grid->columns)
	{
		if (grid->currentArray [row + 1][0] == 'X')
		{
			count++;
		}
	}

	else if ((row + 1) == grid->rows && (column + 1) == grid->columns)
	{
		if (grid->currentArray [0][0] == 'X')
		{
			count++;
		}
	}

	//Top Left Box
	if ((row - 1) >= 0 && (column - 1) >= 0)
	{
		if (grid->currentArray [row - 1][column - 1] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) >= 0 && (column - 1) < 0)
	{
		if (grid->currentArray [row - 1][grid->columns - 1] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) < 0 && (column - 1) >= 0)
	{
		if (grid->currentArray [grid->rows - 1][column - 1] == 'X')
		{
			count++;
		}
	}

	else if ((row - 1) < 0 && (column - 1) < 0)
	{
		if (grid->currentArray [grid->rows - 1][grid->columns - 1] == 'X')
		{
			count++;
		}
	}

	return count;
}

//Decides what the current box becomes based on the pop surrounding it
void DoughnutMode::fate(int pop, int row, int column)
{
	if (pop <= 1)
	{
		grid->futureArray [row][column] = '-';
	}

	else if (pop == 2)
	{
		grid->futureArray [row][column] = grid->currentArray [row][column];
	}

	else if (pop == 3)
	{
		grid->futureArray [row][column] = 'X';
	}

	else if (pop >= 4)
	{
		grid->futureArray [row][column] = '-';
	}
}