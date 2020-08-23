#ifndef Menu_H_
	#include <iostream>
	#include "PersonTree.h"
	using namespace std;
#define Menu_H_
//Header file for main Menu class
class Menu
{
public:
	Menu();
	~Menu();

	void run();
	int display();


	void printOneStudent();
	void changeAdvisorID();
	void printStudentInfo();
	void addStudent();
	void deleteStudent();
	void printStudentAdvisor();

	void printAdviseeInfo();
	void printFacultyInfo();
	void addFaculty();
	void printOneFaculty();
	void deleteFaculty();
	void changeFacAdvisee();
private:
	GenDoubleList<int>* advisees;
	PersonTree<Student*>* studentTree;
	PersonTree<Faculty*>* facultyTree;
};

#endif