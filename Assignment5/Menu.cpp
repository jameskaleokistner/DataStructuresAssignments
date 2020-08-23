#include "Menu.h"


//Where all the guts of the program lie
Menu::Menu()
{
	advisees = new GenDoubleList<int>();
	studentTree = new PersonTree<Student*>();
	facultyTree = new PersonTree<Faculty*>();

	//These are implemented so there are some students and a faculty member to work with when starting the program
	Student* newStudent = new Student(20, "James Kistner", "Senior", "Computer Science", 4.0, 1);
	Student* newStudent2 = new Student(50, "Chase Tullar", "Senior", "Computer Science", 2.0, 1);
	studentTree->insert(newStudent);
	studentTree->insert(newStudent2);
	advisees = new GenDoubleList<int>();
	advisees->insertFront(50);
	advisees->insertFront(20);
	Faculty* newFaculty = new Faculty(1, "Rene German", "PHD", "Computer Science", advisees);
	facultyTree->insert(newFaculty);

}

Menu::~Menu()
{
	delete studentTree;
	delete facultyTree;
	delete advisees;
}

//
void Menu::run()
{
	//runs functions based on what was selected in display method
	int select = display();

	switch (select)
	{
		case 1:
			printStudentInfo();
			break;
		case 2:
			printFacultyInfo();
			break;
		case 3:
			printOneStudent();
			break;
		case 4:
			printOneFaculty();
			break;
		case 5:
			printStudentAdvisor();
			break;
		case 6:
			printAdviseeInfo();
			break;
		case 7:
			addStudent();
			break;
		case 8:
			deleteStudent();
			break;
		case 9:
			addFaculty();
			break;
		case 10:
			deleteFaculty();
			break;
		case 11:
			changeAdvisorID();
			break;
		case 12:
			changeFacAdvisee();
			break;
		case 13:
			//NOT IMPLEMENTED
			break;
		case 14:
			exit(0);
			break;
	}
}

//Method to display all the available options
int Menu::display()
{
	int selection;
	bool loop = true;
	while(loop)
	{
		cout << "\nAvailible commands:\n\t1) Print all students and their information\n\t2) Print all faculty and their information\n\t3) Display student information given their ID" 
		<< "\n\t4) Display faculty information given their ID\n\t5) Print name and info of student's advisor\n\t6) Print all advisees info of a faculty member" 
		<< "\n\t7) Add a new student\n\t8) Delete a student\n\t9) Add a new faculty member\n\t10) Delete a faculty member\n\t11) Change a student's advisor"
		<< "\n\t12) Remove an advisee from a faculty member\n\t13) Rollback (NOT IMPLEMENTED)\n\t14) Exit\nPlease enter (1-14): " << flush;
		cin >> selection;

		for (int i = 1; i < 15; i++)
		{
			if (selection == i)
			{
				loop = false;
			}
		}

		if(loop == true)
		{
			cout << "\nPlease select a VALID number!" << endl;
		}
	}
	return selection;

}

//Method to add a new Student
void Menu::addStudent()
{
	int ID;
	string fName;
	string lName;
	string fullName;
	string rank;
	string major;
	double GPA;
	int advisorID;
	cout << "Please enter the student's ID: " << flush;
	cin >> ID;
	//checks to see if it exists
	Student* tempStud = new Student(ID);
	bool contains = studentTree->contains(tempStud);
	delete tempStud;
	while (contains)
	{
		cout << "Student ID already exists!\nPlease enter a different ID: " << flush;
		cin >> ID;
		Student* tempStud = new Student(ID);
		contains = studentTree->contains(tempStud);
		delete tempStud;
	}
	cout << "Please enter the student's first name: " << flush;
	cin >> fName;

	cout << "Please enter the student's last name: " << flush;
	cin >> lName;

	fullName = fName + " " + lName;
	//checks to make sure input is acceptable
	cout << "Please enter the student's grade level (Freshman, Sophomore, etc...): " << flush;
	cin >> rank;
	bool checkRank = true;
	while (checkRank)
	{
		for (int i = 0; i < rank.length(); i++)
		{
			rank[i] = toupper(rank[i]);
		}

		if (rank == "FRESHMAN" || rank == "SOPHOMORE" || rank == "JUNIOR" || rank == "SENIOR")
		{
			checkRank = false;
		}
		else
		{
			cout << "Student grade level doesn't exist!\nPlease enter the student's grade level (Freshman, Sophomore, etc...): " << flush;
			cin >> rank;
		}
	}

	cout << "Please enter the student's major: " << flush;
	cin >> major;

	//Another check
	cout << "Please enter the student's GPA: " << flush;
	cin >> GPA;

	bool checkGPA = true;
	while (checkGPA)
	{
		if (GPA >= 0.0 && GPA <= 4.0)
		{
			checkGPA = false;
		}
		else
		{
			cout << "Entered GPA is not between 0 and 4!\nPlease enter the student's GPA: " << flush;
			cin >> GPA;
		}
	}

	//Final check to see if advisor exists
	cout << "Please enter the student's advisor ID: " << flush;
	cin >> advisorID;
	Faculty* tempFac = new Faculty(advisorID);
	contains = facultyTree->contains(tempFac);
	delete tempFac;
	while (!contains)
	{
		cout << "Faculty ID doesn't exist!\nPlease enter a different ID: " << flush;
		cin >> advisorID;
		Faculty* tempFac = new Faculty(advisorID);
		contains = facultyTree->contains(tempFac);
		delete tempFac;
	}

	//Creates and adds student to tree displaying the information you selected
	Student* newStudent = new Student(ID, fullName, rank, major, GPA, advisorID);
	cout << "\nID: " << newStudent->getID() << "\nFull Name: " << newStudent->getName() << "\nGrade: " << newStudent->getRank() << "\nMajor: " << newStudent->getMajor()
	<< "\nGPA: " << newStudent->getGPA() << "\nAdvisor ID: " << newStudent->getAdvisorID() << endl; 
	studentTree->insert(newStudent);
	cout << "Student succesfully added!" << endl;
	run();
}

//Same as student method but for faculty
void Menu::addFaculty()
{
	int ID;
	string fName;
	string lName;
	string fullName;
	string rank;
	string department;
	int stuID;
	GenDoubleList<int>* advisees = new GenDoubleList<int>();
	cout << "Please enter the Faculty's ID: " << flush;
	cin >> ID;
	Faculty* tempFac = new Faculty(ID);
	bool contains = facultyTree->contains(tempFac);
	delete tempFac;
	while (contains)
	{
		cout << "Faculty ID already exists!\nPlease enter a different ID: " << flush;
		cin >> ID;
		Faculty* tempFac = new Faculty(ID);
		contains = facultyTree->contains(tempFac);
		delete tempFac;
	}
	cout << "Please enter the faculty member's first name: " << flush;
	cin >> fName;

	cout << "Please enter the faculty member's last name: " << flush;
	cin >> lName;

	fullName = fName + " " + lName;

	cout << "Please enter the faculty member's rank: " << flush;
	cin >> rank;

	cout << "Please enter the faculty member's department: " << flush;
	cin >> department;

	//Allows multiple advisees to be added until the user types -1
	cout << "Please enter the faculty member's advisees ID's, (Or type -1 if this faculty memeber has no advisees): " << flush;
	cin >> stuID;
	while (stuID != -1)
	{
		advisees->insertFront(stuID);
		cout << "Please enter the next advisee ID, Or type -1 if all advisees are added: " << flush;
		cin >> stuID;
	}

	Faculty* newFaculty = new Faculty(ID, fullName, rank, department, advisees);
	cout << "\nID: " << newFaculty->getID() << "\nFull Name: " << newFaculty->getName() << "\nRank: " << newFaculty->getRank() << "\nDepartmnet: " << newFaculty->getDepartment()
	<< "\nAdvisees: " << endl;
	newFaculty->printAdvisees(); 
	facultyTree->insert(newFaculty);
	cout << "Faculty member succesfully added!" << endl;
	run();
}

//Delete method
void Menu::deleteStudent()
{
	int ID;
	cout << "Please enter a student's ID to be deleted: " << flush;
	cin >> ID;
	Student* tempStud = new Student(ID);
	bool delStud = studentTree->deleteRec(tempStud);
	//if statement to check if delete was successful
	delete tempStud;
	if (delStud)
	{
		cout << "Student succesfully deleted!" << endl;
	}
	else
	{
		cout << "Student couldn't be deleted!" << endl;
	}
	run();
}

//same as delete student method
void Menu::deleteFaculty()
{
	int ID;
	cout << "Please enter a faculty member's ID to be deleted: " << flush;
	cin >> ID;
	Faculty* tempFac = new Faculty(ID);
	bool delFac = facultyTree->deleteRec(tempFac);
	delete tempFac;
	if (delFac)
	{
		cout << "Faculty member succesfully deleted!" << endl;
	}
	else
	{
		cout << "Faculty member couldn't be deleted!" << endl;
	}
	run();
}

//Prints info for students
void Menu::printStudentInfo()
{
	studentTree->printStudents();
	run();
}

//prints info for faculty
void Menu::printFacultyInfo()
{
	facultyTree->printFaculty();
	run();
}

//prints a student given their ID
void Menu::printOneStudent()
{
	int ID;
	cout << "Please enter the student's ID to display their information: " << flush;
	cin >> ID;

	Student* tempStud = new Student(ID);
	bool contain = studentTree->contains(tempStud);
	delete tempStud;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> ID;
		if(ID == -1)
		{
			break;
		}
		Student* tempStud = new Student(ID);
		contain = studentTree->contains(tempStud);
		delete tempStud;
	}
	if (ID == -1)
	{
		run();
	}
	else
	{
		TreeNode<Student*>* student = studentTree->returnPerson(ID);
		cout << "\nRetrieved student info with ID: " << student->key->getID() << endl;
		cout << "Student Name: " << student->key->getName() << endl;
		cout << "Student Grade Level: " << student->key->getRank() << endl;
		cout << "Student Major: " << student->key->getMajor() << endl;
		cout << "Student GPA: " << student->key->getGPA() << endl;
		cout << "Student Advisor ID: " << student->key->getAdvisorID() << endl;
		run();
	}

}

//same as printonestudent function
void Menu::printOneFaculty()
{
	int ID;
	cout << "Please enter the Faculty member's ID to display their information: " << flush;
	cin >> ID;

	Faculty* tempFac = new Faculty(ID);
	bool contain = facultyTree->contains(tempFac);
	delete tempFac;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> ID;
		if(ID == -1)
		{
			break;
		}
		Faculty* tempFac = new Faculty(ID);
		contain = facultyTree->contains(tempFac);
		delete tempFac;
	}
	if (ID == -1)
	{
		run();
	}
	else
	{
		TreeNode<Faculty*>* faculty = facultyTree->returnPerson(ID);
		cout << "\nRetrieved faculty info with ID: " << faculty->key->getID() << endl;
		cout << "Faculty Name: " << faculty->key->getName() << endl;
		cout << "Faculty Rank: " << faculty->key->getRank() << endl;
		cout << "Faculty Department: " << faculty->key->getDepartment() << endl;
		cout << "Faculty Advisees IDs: " << endl;
		faculty->key->printAdvisees();
		run();
	}

}

//changes a student's advisor
void Menu::changeAdvisorID()
{
	int AdvisorID;
	int StudentID;
	cout << "Enter the student's ID: " << flush;
	cin >> StudentID;


	Student* tempStud = new Student(StudentID);
	bool contain = studentTree->contains(tempStud);
	delete tempStud;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> StudentID;
		if(StudentID == -1)
		{
			break;
		}
		Student* tempStud = new Student(StudentID);
		contain = studentTree->contains(tempStud);
		delete tempStud;
	}

	cout << "Enter the student's new Advisor ID: " << endl;
	cin >> AdvisorID;

	TreeNode<Student*>* student = studentTree->returnPerson(StudentID);
	student->key->setAdvisorID(AdvisorID);
	run();
}

//Prints a student's advisor
void Menu::printStudentAdvisor()
{
	int ID;
	cout << "Enter the student's ID: " << flush;
	cin >> ID;

	Student* tempStud = new Student(ID);
	bool contain = studentTree->contains(tempStud);
	delete tempStud;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> ID;
		if(ID == -1)
		{
			break;
		}
		Student* tempStud = new Student(ID);
		contain = studentTree->contains(tempStud);
		delete tempStud;
	}
	TreeNode<Student*>* student = studentTree->returnPerson(ID);
	int advisor = student->key->getAdvisorID();

	TreeNode<Faculty*>* faculty = facultyTree->returnPerson(advisor);
	cout << "\nRetrieved faculty info with ID: " << faculty->key->getID() << endl;
	cout << "Faculty Name: " << faculty->key->getName() << endl;
	cout << "Faculty Rank: " << faculty->key->getRank() << endl;
	cout << "Faculty Department: " << faculty->key->getDepartment() << endl;
	cout << "Faculty Advisees IDs: " << endl;
	faculty->key->printAdvisees();
	run();


}

//prints all the info of a faculty member's advisees
void Menu::printAdviseeInfo()
{
	int ID;
	cout << "Enter the faculty member's ID: " << flush;
	cin >> ID;

	Faculty* tempFac = new Faculty(ID);
	bool contain = facultyTree->contains(tempFac);
	delete tempFac;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> ID;
		if(ID == -1)
		{
			break;
		}
		Faculty* tempFac = new Faculty(ID);
		contain = facultyTree->contains(tempFac);
		delete tempFac;
	}
	TreeNode<Faculty*>* faculty = facultyTree->returnPerson(ID);
	GenNode<int>* advisee = faculty->key->getFront();

	//while statement to loop through all advisees
	while(advisee != nullptr)
	{
		TreeNode<Student*>* student = studentTree->returnPerson(advisee->data);
		cout << "\nStudent ID: " << student->key->getID() << endl;
		cout << "Student Name: " << student->key->getName() << endl;
		cout << "Student Grade Level: " << student->key->getRank() << endl;
		cout << "Student Major: " << student->key->getMajor() << endl;
		cout << "Student GPA: " << student->key->getGPA() << endl;
		cout << "Student Advisor ID: " << student->key->getAdvisorID() << endl;
		advisee = advisee->next;
	}

	run();
}

//Method to delete faculty advisee
void Menu::changeFacAdvisee()
{
	int ID;
	cout << "Enter the faculty member's ID: " << flush;
	cin >> ID;

	Faculty* tempFac = new Faculty(ID);
	bool contain = facultyTree->contains(tempFac);
	delete tempFac;
	while(!contain)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> ID;
		if(ID == -1)
		{
			break;
		}
		Faculty* tempFac = new Faculty(ID);
		contain = facultyTree->contains(tempFac);
		delete tempFac;
	}
	TreeNode<Faculty*>* faculty = facultyTree->returnPerson(ID);

	int stuID;
	cout << "Enter the student's ID: " << flush;
	cin >> stuID;

	Student* tempStud = new Student(stuID);
	bool contains = studentTree->contains(tempStud);
	delete tempStud;
	while(!contains)
	{
		cout << "ID number does not exist!\nEnter a different ID, or type -1 to exit: " << flush;
		cin >> stuID;
		if(stuID == -1)
		{
			break;
		}
		Student* tempStud = new Student(stuID);
		contains = studentTree->contains(tempStud);
		delete tempStud;
	}

	//check to see if the user wants to exit
	if(stuID == -1)
	{
		run();
	}
	else
	{
		GenNode<int>* advisee = faculty->key->getFront();
		cout << advisee->data << endl;
		while(advisee->data != stuID)
		{
			if(advisee == nullptr)
			{
				break;
			}
			advisee = advisee->next;
		}
		//if student isn't found
		if(advisee == nullptr)
		{
			run();
		}
		else
		{
			Student* tempStud = new Student(stuID);
			bool delStud = studentTree->deleteRec(tempStud);
			delete tempStud;
			if (delStud)
			{
				cout << "Student succesfully deleted!" << endl;
			}
			else
			{
				cout << "Student couldn't be deleted!" << endl;
			}
			run();
		}

	}



}	