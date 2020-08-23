#include "A1.h"
#include <cmath>
#include <math.h>
#include <iostream>
#include <stdlib.h> 

#define PI 3.14159265

using namespace std;
//variables used to count
int DNA::sum;
int DNA::A;
int DNA::C;
int DNA::T;
int DNA::G;
int DNA::AA;
int DNA::AC;
int DNA::AT;
int DNA::AG;
int DNA::CA;
int DNA::CC;
int DNA::CT;
int DNA::CG;
int DNA::TA;
int DNA::TC;
int DNA::TT;
int DNA::TG;
int DNA::GA;
int DNA::GC;
int DNA::GT;
int DNA::GG;

//method to get a nucleotide based on its probability
string DNA::getChar()
{
	while (true)
	{
		//double between 0 and 1
		double a = ((double) rand() / (RAND_MAX));

		//if statements that calc the percent probability of ACTG and compares it to the double. If "a" is less than or equal to the probability, then the string is returned
		if (a <= (float(DNA::A))/float(DNA::sum))
		{
			return "A";
		}

		a = ((double) rand() / (RAND_MAX));

		if (a <= (float(DNA::C))/float(DNA::sum))
		{
			return "C";
		}

		a = ((double) rand() / (RAND_MAX));

		if (a <= (float(DNA::T))/float(DNA::sum))
		{
			return "T";
		}

		a = ((double) rand() / (RAND_MAX));

		if (a <= (float(DNA::G))/float(DNA::sum))
		{
			return "G";
		}
	}
}

//Method used to generate random length of a string to append based on the mean and standard deviation
int DNA::gaussin(int mean, int sd)
{
	//randomly calculates a and b between 0 and 1
	double a = ((double) rand() / (RAND_MAX));
	double b = ((double) rand() / (RAND_MAX));

	b = cos(2 * PI * b);
	//checks to see if b is negative, and makes it positive if it is
	if (b < 0)
	{
		b = ( b * -1);
	}

	double c = sqrt(((-2)*log(a)))* b;
	//calcs random length
	float d = (sd * c) + mean;
	//turns random length into an int
	int roundUp = ceil(d);

	return roundUp;

}



//Method to find the length of a string
int DNA::lineLength(string line)
{
	return line.length();
}

//Methods used for calculating different parts of the variance
int DNA::varianceSquare(int mean, int lineL)
{
	int mml = lineL - mean;
	float squared = pow(mml, 2);
	return squared;
}

float DNA::variance(int varSquare, int dataL)
{
	return (float(varSquare)/float((dataL - 1)));
}

//Method for counting nucleotides
void DNA::charCalc(char c)
{
	if (c == 'A')
	{
		DNA::sum++;
		DNA::A++;
	}
	else if (c == 'C')
	{
		DNA::sum++;
		DNA::C++;
	}
	else if (c == 'T')
	{
		DNA::sum++;
		DNA::T++;
	}
	else if (c == 'G')
	{
		DNA::sum++;
		DNA::G++;
	}
}

//Resets variables if new files is being read from
void DNA::resetNukes()
{
	DNA::sum = 0;
	DNA::A = 0;
	DNA::C = 0;
	DNA::T = 0;
	DNA::G = 0;
	DNA::AA = 0;
	DNA::AC = 0;
	DNA::AT = 0;
	DNA::AG = 0;
	DNA::CA = 0;
	DNA::CC = 0;
	DNA::CT = 0;
	DNA::CG = 0;
	DNA::TA = 0;
	DNA::TC = 0;
	DNA::TT = 0;
	DNA::TG = 0;
	DNA::GA = 0;
	DNA::GC = 0;
	DNA::GT = 0;
	DNA::GG = 0;
}

//Method that uses char count and also counts the nucleotide bigrams
void DNA::nukeCount(string line)
{
	bool control = false;
	char a;
	string concat;

	for (int i = 0; i < line.length(); i++)
	{
		char b = line[i];
		b = toupper(b);

		DNA::charCalc(b);

		if (DNA::A == 0 && DNA::C == 0 && DNA::T == 0 && DNA::G == 0)
		{
		cout << "No valid DNA Strings!" << endl;
		}

		else
		{
			if (control == false)
			{
				a = b;
				control = true;
			}

			else if (control == true)
			{
				concat += a;
				concat += b;

				if (concat == "AA")
				{
					DNA::AA++;
				}

				else if (concat == "AC")
				{
					DNA::AC++;
				}

				else if (concat == "AT")
				{
					DNA::AT++;
				}

				else if (concat == "AG")
				{
					DNA::AG++;
				}

				else if (concat == "CA")
				{
					DNA::CA++;
				}

				else if (concat == "CC")
				{
					DNA::CC++;
				}

				else if (concat == "CT")
				{
					DNA::CT++;
				}

				else if (concat == "CG")
				{
					DNA::CG++;
				}

				else if (concat == "TA")
				{
					DNA::TA++;
				}

				else if (concat == "TC")
				{
					DNA::TC++;
				}

				else if (concat == "TT")
				{
					DNA::TT++;
				}

				else if (concat == "TG")
				{
					DNA::TG++;
				}

				else if (concat == "GA")
				{
					DNA::GA++;
				}

				else if (concat == "GC")
				{
					DNA::GC++;
				}

				else if (concat == "GT")
				{
					DNA::GT++;
				}

				else if (concat == "GG")
				{
					DNA::GG++;
				}

				control = false;
				concat = "";

			}
		}
	}
}

//Method that is basically a toString for the nucleotide stats
string DNA::getNukes()
{
	string ret = "\nTOTAL AMOUNT OF NUCLEOTIDES: " + to_string(DNA::sum) + "\n\nThere were " + to_string(DNA::A) + " A's\nThere were " + 
	to_string(DNA::C) + " C's\nThere were " + to_string(DNA::T) + " T's\nThere were " + to_string(DNA::G) + " G's\nAA's: " + to_string(DNA::AA) + "\nAC's: " +
	to_string(DNA::AC) + "\nAT's: " + to_string(DNA::AT) + "\nAG's: " + to_string(DNA::AG) + "\nCA's: " + to_string(DNA::CA) + "\nCC's: " + to_string(DNA::CC) + 
	"\nCT's: " + to_string(DNA::CT) + "\nCG's: " + to_string(DNA::CG) + "\nTA's: " + to_string(DNA::TA) + "\nTC's: " + to_string(DNA::TC) + "\nTT's: " + to_string(DNA::TT) +
	"\nTG's: " + to_string(DNA::TG) + "\nGA's: " + to_string(DNA::GA) + "\nGC's: " + to_string(DNA::GC) + "\nGT's: " + to_string(DNA::GT) + "\nGG's: " + to_string(DNA::GG);
	return ret;
}

