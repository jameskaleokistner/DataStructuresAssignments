#include "menu.h"

//Constructor
Menu::Menu(string file)
{
	this->fileName = file;

}


//Destructor
Menu::~Menu()
{
}

//Guts of program that runs everything
void Menu::run()
{
	//Open the input file
	FileInput file;
	file.openFile(this->fileName);

	//First line of code has the array size
	file.inputFile >> this->arraySize;

	//Declar four test arrays
	double arrayOne [arraySize];
	double arrayTwo [arraySize];
	double arrayThree [arraySize];
	double arrayFour [arraySize];

	double line;
	int i = 0;
	//Filling up the arrays
	while(file.inputFile >> line)
	{
		arrayOne[i] = line;
		arrayTwo[i] = line;
		arrayThree[i] = line;
		arrayFour[i] = line;
		i++;
	}
	file.closeFile();

	//Bubble Sort algorithm
	time_t start = time(0);
	bubbleSort(arrayOne);
	double seconds_since_start = difftime( time(0), start);
	cout << "Bubble sort time: " << seconds_since_start << endl;

	//Merge Sort algorithm
	start = time(0);
	mergeSort(arrayTwo, 0, arraySize - 1);
	seconds_since_start = difftime( time(0), start);
	cout << "Merge sort time: " << seconds_since_start << endl;

	//Insertion Sort algorithm
	start = time(0);
	insertionSort(arrayThree, arraySize);
	seconds_since_start = difftime( time(0), start);
	cout << "Insertion sort time: " << seconds_since_start << endl;

	//Quick Sort algorithm
	start = time(0);
	quickSort(arrayFour, 0, arraySize - 1);
	seconds_since_start = difftime( time(0), start);
	cout << "Quick sort time: " << seconds_since_start << endl;

}

//Prints a given array of doubles, used to make sure arrays were sorted correctly
void Menu::printArray(double A[], int size) 
{ 
    for (int i = 0; i < size; i++)
    {
    	cout << A[i] << endl;
    } 
} 

//Basic bubble sort
void Menu::bubbleSort(double arr[])
{
	int i, j; 
	for (i = 0; i < arraySize-1; i++)       
  	{
    	double temp = 0.0;    
       	for (j = 0; j < arraySize-i-1; j++)
       	{
   			if (arr[j] > arr[j+1])
   			{
   				temp = arr[j];
   				arr[j] = arr[j+1];
   				arr[j+1] = temp;
   			} 
       	}
    }
}

//Insertion sort
void Menu::insertionSort(double arr[], int n) 
{ 
   int i, j;
   double key; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

//Main meat of the merge sort algortihm implemented for doubles
void Menu::merge(double arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    double L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
//Edited merge sort from the internet adapted to sort doubles
void Menu::mergeSort(double arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
//Used for quick sort
int Menu::partition (double arr[], int low, int high) 
{ 
    double pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
//implementation of quick sort
void Menu::quickSort(double arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

//swaps two double values with each other
void Menu::swap(double* a, double* b) 
{ 
    double t = *a; 
    *a = *b; 
    *b = t; 
}   