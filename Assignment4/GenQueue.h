#ifndef GenQueue_H_
	#include <iostream>
	using namespace std;
#define GenQueue_H_

template <class T> class GenQueue
{
public:
	GenQueue();
	GenQueue(int maxSize);
	~GenQueue();
	void insert(T data);
	T remove();
	T peek();

	bool isFull();
	bool isEmpty();
	int getSize();

private:
	int front;
	int rear;
	int numElements;
	int size;
	T* myQueue;
};

template <class T>
GenQueue<T>::GenQueue()
{
	myQueue = new T[10];
	size = 10;
	numElements = 0;
	front = 0;
	rear = -1;
}

template <class T>
GenQueue<T>::GenQueue(int maxSize)
{
	myQueue = new T[maxSize];
	size = maxSize;
	numElements = 0;
	front = 0;
	rear = -1;
}

template <class T>
GenQueue<T>::~GenQueue()
{
	delete [] myQueue;
}

template <class T>
void GenQueue<T>::insert(T data)
{
	bool check = isFull();
	if (check)
	{
		cout << "Queue is Full!" << endl;
	}

	else
	{
		if (rear == size -1)
		{
			rear = -1;
		}
		myQueue[++rear] = data;
		numElements++;
	}

}

template <class T>
T GenQueue<T>::remove()
{
	bool check = isEmpty();
	if (check)
	{
		cout << "Queue is Empty!" << endl;
	}
	else
	{
		T data = NULL;
		data = myQueue[front];
		front++;
		if (front == size)
		{
			front = 0;
		}
		numElements--;
		return data;
	}
}

template <class T>
T GenQueue<T>::peek()
{
	return myQueue[front];
}

template <class T>
bool GenQueue<T>::isEmpty()
{
	return (numElements == 0);
}

template <class T>
bool GenQueue<T>::isFull()
{
	return (numElements == size);
}

template <class T>
int GenQueue<T>::getSize()
{
	return numElements;
}

#endif