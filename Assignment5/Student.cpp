#include "Person.cpp"	

//Basic Implementation of Student class
Student::Student(int ID)
{
	this->ID = ID;
 	this->name = "";
	this->rank = "";

	this->major = "";
	this->GPA = 0.0;
	this->advisorID = 0;
}

Student::Student(int ID, string name, string rank, string major, double GPA, int advisorID)
{
	this->ID = ID;
	this->name = name;
	this->rank = rank;
	
	this->major = major;
	this->GPA = GPA;
	this->advisorID = advisorID;
}

Student::~Student()
{
}

int Student::getID()
{
	return this->ID;
}

string Student::getName()
{
	return this->name;
}

string Student::getRank()
{
	return this->rank;
}

string Student::getMajor()
{
	return this->major;
}

double Student::getGPA()
{
	return this->GPA;
}

int Student::getAdvisorID()
{
	return this->advisorID;
}

void Student::setAdvisorID(int ID)
{
	this->advisorID = ID;
}