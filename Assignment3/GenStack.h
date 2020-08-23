#ifndef GenStack_H_
	#include <iostream>
	using namespace std;
#define GenStack_H_
template <class T> class GenStack
{
public:
	GenStack(int s);
	GenStack();
	~GenStack();

	void push(T pushVal);
	T pop();
	T peek();
	void resize();

	bool isEmpty();
	bool isFull();


private:
		int size;
		int top; 
		T* stackPtr;
};

template <class T>
GenStack<T>::GenStack()
{
	size = 25;
	top = -1;
	stackPtr = new T[size];
}

template <class T>
GenStack<T>::GenStack(int s)
{
	size = s;
	top = -1;
	stackPtr = new T[size];
}

template <class T>
GenStack<T>::~GenStack()
{
	delete [] stackPtr;
}

template <class T>
void GenStack<T>::push(T pushVal)
{
	if (GenStack<T>::isFull())
	{
		GenStack<T>::resize();
		++top;
		stackPtr[top] = pushVal;
	}
	else if (!GenStack<T>::isFull())
	{
		++top;
		stackPtr[top] = pushVal;
	}
}

template <class T>
T GenStack<T>::pop()
{
	T data;
	if (!GenStack<T>::isEmpty())
	{
		data = stackPtr[top];
		--top;
	}
	else
	{
		cout << "Stack Empty!" << endl;
	}
	return data;
}

template <class T>
T GenStack<T>::peek()
{
	T data;
	if (!GenStack<T>::isEmpty())
	{
		data = stackPtr[top];
	}
	else
	{
		cout << "Stack Empty!!!" << endl;
	}
	return data;
}

template <class T>
bool GenStack<T>::isEmpty()
{ 
  return top == -1; 
}

template <class T>
bool GenStack<T>::isFull() 
{ 
  return top == size - 1; 
}

//resize method that doubles the current size of the stack array
template <class T>
void GenStack<T>::resize()
{
	int newSize = (size * 2);
	T* newStackPtr = new T[newSize];
	for (int i = 0; i < size; i++)
	{
		stackPtr[i] = newStackPtr[i];
	}
	delete [] stackPtr;
	stackPtr = newStackPtr;
}


#endif

