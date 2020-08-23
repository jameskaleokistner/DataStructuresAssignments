#include <iostream>
using namespace std;

template <class T>
class ListInterface
{
public:
	virtual void insertFront(T d);
	virtual void insertBack(T d);
	virtual T removeBack();
	virtual T removeFront();
	virtual void printList();
	virtual int find(T d);
	virtual unsigned int getSize();
	virtual T deletePos(int index);
};