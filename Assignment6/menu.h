#ifndef Menu__H__
	#include <iostream>
	#include "FileInput.h"
	#include <time.h>
	using namespace std;
#define Menu__H__

class Menu
{
public:
	Menu(string file);
	~Menu();
	void run();
	void printArray(double A[], int size); 
	void bubbleSort(double arr[]);
	void merge(double arr[], int l, int m, int r);
	void mergeSort(double arr[], int l, int r); 
	int partition (double arr[], int low, int high);
	void quickSort(double arr[], int low, int high);
	void swap(double* a, double* b);
	void insertionSort(double arr[], int n); 

private:
	string fileName;
	int arraySize;
};

#endif