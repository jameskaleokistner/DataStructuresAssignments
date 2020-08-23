
//This cpp file was used to write a given amount of doubles to a given file

/*#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	int nums;
	cout << "Please enter the amount of numbers to be written to the file: " << flush;
	cin >> nums;

	ofstream file;
	file.open ("test.txt");
	file << nums << "\n";
	for (int i = 0; i <= nums; i++)
	{
		double random = ((double)rand() / RAND_MAX) * (1000);
		file << random << "\n";
	}

	cout << "\nExecuted Program Successfully" << endl;
	file.close();
	return 0;
}*/