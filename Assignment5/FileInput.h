#ifndef FileInput_H_
    #include <iostream>
    using namespace std;
    #include <fstream>
#define FileInput_H_
class FileInput
{
public:
    void openFile(string name);
    void closeFile();
private:
	ifstream inputFile;
	ofstream newFile;

};
#endif