#include "Grid.h"


//Empty constructor
Grid::Grid()
{
	//sets rows to 5
	currentArray = new char* [5];
	futureArray = new char* [5];
	for (int i = 0; i < 5; i++)
	{
		//sets columns to 7
		currentArray[i] = new char[7];
		futureArray[i] = new char[7];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			//Sets all data in array to null
			currentArray [i][j] = '\0';
			futureArray [i][j] = '\0';
		}
	}
	//sets member variables to default values
	this->rows = 5;
	this->columns = 7;
	this->infinite = true;
}

//Creates grid given rows and columns
Grid::Grid(int rows, int columns)
{
	//sets row sizes
	currentArray = new char*[rows];
	futureArray = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		//sets column sizes
		currentArray[i] = new char [columns];
		futureArray[i] = new char [columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//sets all data in 2d array to null
			currentArray [i][j] = '\0';
			futureArray [i][j] = '\0';
		}
	}

	//sets member variables to default
	this->rows = rows;
	this->columns = columns;
	this->infinite = true;;
}

//Copy constructor
Grid::Grid(const Grid &grid)
{
	//Sets rows of new grid to old grid sizes
	this->currentArray = new char*[grid.rows];
	this->futureArray = new char*[grid.rows];
	for (int i = 0; i < grid.rows; i++)
	{
		//Sets columns of new grid to old grid sizes
		this->currentArray[i] = new char [grid.columns];
		this->futureArray[i] = new char [grid.columns];
	}
	for (int i = 0; i < grid.rows; i++)
	{
		for (int j = 0; j < grid.columns; j++)
		{
			//Copies data from 2D array
			this->currentArray [i][j] = grid.currentArray [i][j];
			this->futureArray [i][j] = grid.futureArray [i][j];
		}
	}

	//Sets member variables to the same as given grid
	this->rows = grid.rows;
	this->columns = grid.columns;
	this->infinite = grid.infinite;
}

//Destructor
Grid::~Grid()
{
	//deletes dynamically allocated memory
	for (int i = 0; i < this->rows; i++)
	{
		delete [] currentArray [i];
		delete [] futureArray [i];
	}
	cout << "Grid Destructor Called" << endl;
}

//Method to copy current array to future array
void Grid::copyFuture()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			//copies current array to data in the future array
			this->currentArray [i][j] = this->futureArray[i][j];
			//sets future array data to null
		}
	}
}

//method to output grid
void Grid::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j < columns - 1)
			{
				cout << currentArray [i][j] << flush;
			}

			else if (j == columns - 1)
			{
				cout << currentArray [i][j] << endl;
			}
			
		}
	}
}

//method called when printing to file
string Grid::printFile()
{
	string returns;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (j < this->columns - 1)
			{
				//adds to a string
				returns += currentArray [i][j];
			}

			else if (j == this->columns - 1)
			{
				//adds to a string if new line
				returns += currentArray [i][j];
				returns += "\n";
			}
			
		}
	}
	return returns;
}

//Method called to populate a grid given a density
void Grid::random(float density)
{
	int r = rows;
	int c = columns;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//creates a number between 0 and 1
			double a = ((double) rand() / (RAND_MAX));
			//if statement that relies on probability to populate or to leave empty
			if (a <= density)
			{
				currentArray [i][j] = 'X';
				futureArray [i][j] = 'X';
			}
			else
			{
				currentArray [i][j] = '-';
				futureArray [i][j] = '-';
			}
			
		}
	}
}

//Method used to generate grid given the amount of lines and the strings that contain chars either X or -
void Grid::generateGrid(string line, int count)
{
	for (int i = 0; i < line.size(); i++)
	{
		//Checks to see if the char is a number
		if (!isdigit(line[i]))
		{
			if (line[i] == '-')
			{
				this->currentArray [count][i] = '-';
				this->futureArray [count][i] = '-';
			}

			else if (line[i] == 'X')
			{
				this->currentArray [count][i] = 'X';
				this->futureArray [count][i] = '-';
			}

			else //Sets grid to - if anything else is given
			{
				this->currentArray [count][i] = '-';
				this->futureArray [count][i] = '-';
			}
		}
	}
}

//Method to check if the grid ends
bool Grid::isInfinite()
{
	//count that keeps tracks of the amount of - in the program
	int count = 0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (this->currentArray [i][j] == '-')
			{
				count++;
			}
		}
	}

	//If statement that checks if all of the grid slots are -
	if (count == (this->rows * this->columns))
	{
		return false;
	}

	count = 0;

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (this->currentArray [i][j] == this->futureArray [i][j])
			{
				count++;
			}
		}
	}

	if (count == (this->rows * this->columns))
	{
		return false;
	}

	return true;
}


