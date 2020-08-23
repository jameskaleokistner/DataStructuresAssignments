#include "Person.cpp"

//Basic implementaion of methods needed for Faculty class
Faculty::Faculty(int ID)
{
	this->ID = ID;
	this->name = "";
	this->rank = "";

	this->department = "";
	this->advisees = new GenDoubleList<int>();
}

Faculty::Faculty(int ID, string name, string rank, string department, GenDoubleList<int>* advisees)
{
	this->ID = ID;
	this->name = name;
	this->rank = rank;
	this->department = department;
	this->advisees = advisees;
}

Faculty::~Faculty()
{
	delete advisees;
}

int Faculty::getID()
{
	return this->ID;
}

string Faculty::getName()
{
	return this->name;
}

string Faculty::getRank()
{
	return this->rank;
}

string Faculty::getDepartment()
{
	return this->department;
}

GenDoubleList<int>* Faculty::getAdvisees()
{
	return this->advisees;
}

//Used for functionality in program
void Faculty::printAdvisees()
{
	this->advisees->printList();
}

//Used for functionality in program
GenNode<int>* Faculty::getFront()
{
	return advisees->returnFront();
}