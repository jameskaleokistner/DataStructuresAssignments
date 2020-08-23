#include <iostream>
using namespace std;
#include "GenDoubleList.cpp"


template <class T> 
class Queue
{
public:
	Queue();
	~Queue();


	void insert(T d);
	T remove();
	//T peek();
	void printQueue();
	unsigned int getSize();

private:
	unsigned int size;
	GenDoubleList<T>* myQueue;
};

template <class T>
Queue<T>::Queue()
{
	myQueue = new GenDoubleList<T>();
	size = 0;
}

template <class T>
Queue<T>::~Queue()
{
	cout << "Doubly Linked List Queue Deleted!" << endl;
}

template <class T>
unsigned int Queue<T>::getSize()
{
	return size;
}

template <class T>
void Queue<T>::printQueue()
{
	myQueue->printList();
}


template <class T>
void Queue<T>::insert(T d)
{
	myQueue->insertBack(d);
}

template <class T>
T Queue<T>::remove()
{
	return myQueue->removeFront();;
}

