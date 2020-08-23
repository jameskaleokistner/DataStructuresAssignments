#include "Syntax.h"

//Only constructor that sets filename
Syntax::Syntax(string fileName)
{
	this->fileName = fileName;
}

//Pointless destructor
Syntax::~Syntax()
{
	cout << "\nSyntax Checker Deleted" << endl;
}

//Main function of syntax that runs all the processes
void Syntax::run()
{
	//Opens file
	FileInput file;
	file.openFile(this->fileName);
	string fLine;
	//Generates Stack
	GenStack <char> stack(20);
	//Counts the number of lines
	int count = 1;
	//While loop reads in file
	while(file.inputFile >> fLine)
	{
		for (int i = 0; i < fLine.length(); i++)
		{
			bool compare = true;
			char c;

			//Pushes opener delimiters
			if (fLine[i] == '(')
			{
				stack.push(fLine[i]);
			}
			else if (fLine[i] == '[')
			{
				stack.push(fLine[i]);
			}
			else if (fLine[i] == '{')
			{
				stack.push(fLine[i]);
			}

			//Pops stack and compares if delimiter is found
			if (fLine[i] == ')')
			{
				//Checks to make sure there is an opener
				if (stack.isEmpty())
				{
					cout << "Found: " << fLine[i] << " and there was no opener!" << endl;
					exit(0);
				}
				//Pops and compares
				//If they aren't the same the bool compare is set to false
				c = stack.pop();
				compare = Syntax::compare(c, fLine[i]);
			}

			else if (fLine[i] == ']')
			{
				if (stack.isEmpty())
				{
					cout << "Found: " << fLine[i] << " and there was no opener!" << endl;
					exit(0);
				}
				c = stack.pop();
				compare = Syntax::compare(c, fLine[i]);
			}

			else if (fLine[i] == '}')
			{
				if (stack.isEmpty())
				{
					cout << "Found: " << fLine[i] << " and there was no opener!" << endl;
					exit(0);
				}
				c = stack.pop();
				compare = Syntax::compare(c, fLine[i]);
			}

			//If error, error message to console with what was expected on which line and what was found
			if (!compare)
			{
				cout << "Error found on line: " << count << "\nFound: " << fLine[i] << "\nExpected: " << Syntax::inverse(c) << endl;
				exit(0);
			}

		}
		//Increments the line
		count++;

	}
	//Checks to make sure openers are closed
	if (!stack.isEmpty())
	{
		string missed;
		while(!stack.isEmpty())
		{
			char c = stack.pop();
			missed += c;
		}
		cout << "\nReached the end of the file and expected a closing to: " << missed << endl;
		exit(0);
	}
	//Prints message if program is correct
	cout << "\n\t$$ SUCCESS NO ERRORS FOUND $$" << endl;
}

//Method that compares chars to makes sure there is an open and close pair
bool Syntax::compare(char c, char d)
{
	if ((c == '(' && d == ')') || (c == '[' && d == ']') || (c == '{' && d == '}'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Inverse is called to show what should be expected when there is an error
char Syntax::inverse(char c)
{
	if (c == '(')
	{
		return ')';
	}

	else if (c == ')')
	{
		return '(';
	}

	else if (c == '{')
	{
		return '}';
	}

	else if (c == '}')
	{
		return '{';
	}

	else if (c == '[')
	{
		return ']';
	}

	else if (c == ']')
	{
		return '[';
	}
}


