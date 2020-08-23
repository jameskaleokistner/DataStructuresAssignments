#ifndef A1_H_
#define A1_H_
#include <iostream>
using namespace std;

class DNA
{
public:
	static int lineLength(string line);
	static int varianceSquare(int mean, int lineL);
	static float variance(int varSquare, int dataL);
	static void charCalc(char c);
	static string getNukes();
	static void nukeCount(string line);
	static void resetNukes();
	static int gaussin(int mean, int variance);
	static string getChar();
private:
	static int sum;
	static int A;
	static int C;
	static int T;
	static int G;
	static int AA;
	static int AC;
	static int AT;
	static int AG;
	static int CA;
	static int CC;
	static int CT;
	static int CG;
	static int TA;
	static int TC;
	static int TT;
	static int TG;
	static int GA;
	static int GC;
	static int GT;
	static int GG;
};
	

#endif