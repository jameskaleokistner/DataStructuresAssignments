#include "Window.h"

Window::Window(int num)
{
	numWindows = num;
	myArray = new int[num];
	for(int i = 0; i < num; i++)
	{
		myArray[i] = -1;
	}
}

Window::~Window()
{
	delete [] myArray;
	cout << "Windows Deleted" << endl;
}

int Window::isOpen()
{
	int ret = -1;
	for(int i = 0; i < numWindows; i++)
	{
		if (myArray[i] == -1)
		{
			ret = i;
			return ret;
		}
	}
	return ret;
}

void Window::fill(int index, Student iStudent)
{
	myArray[index] = iStudent.waitTime;
}

void Window::checkWindows()
{
	for(int i = 0; i < numWindows; i++)
	{
		if (myArray[i] <= 0)
		{
			myArray[i] = -1;
		}
	}
}

void Window::clockTick()
{
	for(int i = 0; i < numWindows; i++)
	{
			myArray[i] -= 1;
	}

}