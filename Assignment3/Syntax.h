#ifndef Syntax_H_
	#include "FileInput.h"
	#include "GenStack.h"
	#include <fstream>
	#include <iostream>
	using namespace std;
#define Syntax_H_
class Syntax
{
public:
	Syntax(string fileName);
	~Syntax();

	char inverse(char c);
	void run();
	bool compare(char c, char d);

private:
	string fileName;

};
#endif
