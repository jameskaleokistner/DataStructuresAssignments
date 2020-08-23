#ifndef Person_H_
	#include <iostream>
	#include "GenDoubleList.h"
	using namespace std;
#define Person_H_


//This class has the virtual Person which both Student and Faculty classes inherit from
class Person
{
	public:
		//The methods inherited by Student and Faculty objects
		virtual int getID() {return ID;}
		virtual string getName() {return name;}
		virtual string getRank() {return rank;}

	private:
		//Member variables being inherited
		int ID;
		string name;
		string rank;

};

//Student class that inherits from Person
class Student : public Person
{
public:
	Student(int ID);
	Student(int ID, string name, string rank, string major, double GPA, int advisorID);
	~Student();

	int getID();
	string getName();
	string getRank();

	string getMajor();
	double getGPA();
	int getAdvisorID();
	void setAdvisorID(int ID);
private:
	int ID;
	string name;
	string rank;

	string major;
	double GPA;
	int advisorID;
};

//Faculty class that inherits from person
class Faculty : public Person
{
public:
	Faculty(int ID);
	Faculty(int ID, string name, string rank, string department, GenDoubleList<int>* advisees);
	~Faculty();

	int getID();
	string getName();
	string getRank();

	GenNode<int>* getFront();
	string getDepartment();
	GenDoubleList<int>* getAdvisees();
	void printAdvisees();
private:
	int ID;
	string name;
	string rank;

	string department;
	GenDoubleList<int>* advisees;
};

#endif