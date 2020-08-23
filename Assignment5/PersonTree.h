#ifndef PersonTree_H_
	#include "BST.cpp"
	#include "Person.cpp"
#define PersonTree_H_


//This class inherits from the generic BST
//It is also Generic, but it has fucntions for both Student and Faculty objects
template <class T>
class PersonTree : public BST<T>
{
public:
	PersonTree();
	~PersonTree();

	//Universal methods
	bool isEmpty();
	void insert(T key);
	bool contains(T key);
	bool deleteRec(T key); //recursive
	TreeNode<T>* returnPerson(int ID); 

	//Student Specific
	void printStudents(); //In-order Traversal recurrsive
	void printS(TreeNode<T>* node);

	//Faculty Specific
	void printFaculty(); //In-order Traversal recurrsive
	void printF(TreeNode<T>* node);

private:
	TreeNode<T>* root;
};

template<class T>
PersonTree<T>::PersonTree()
{
	root = nullptr;
}

template<class T>
PersonTree<T>::~PersonTree()
{
	TreeNode<T>* node = this->root;
	BST<T>::deleteTree(node);
}

template<class T>
void PersonTree<T>::insert(T key)
{
	TreeNode<T>* node = new TreeNode<T>(key);

	if (isEmpty())
	{
		root = node;
	}
	else
	{
		TreeNode<T>* current = root;
		TreeNode<T>* parent = nullptr;

		while(true)
		{
			parent = current;

			if(key->getID() < current->key->getID())
			{
				current = current->left;
				if (current == nullptr)
				{
					parent->left = node;
					break;
				}
			}
			else
			{
				current = current->right;
				if (current == nullptr)
				{
					parent->right = node;
					break;
				}
			}
		}

	}
}

template<class T>
bool PersonTree<T>::contains(T key)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		
		TreeNode<T>* current = root;
		while(true)
		{
			if(current == nullptr)
			{
				return false;
			}

			if(current->key->getID() == key->getID())
			{
				break;
			}
			else if (key->getID() < current->key->getID())
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
	}
	return true;
}

template<class T>
bool PersonTree<T>::deleteRec(T key)
{
	if (!contains(key))
	{
		return false;
	}
	else
	{
		TreeNode<T>* parent = root;
		TreeNode<T>* current = root;
		bool isLeft = true;

		//search for node
		while(current->key->getID() != key->getID())
		{
			parent = current;

			if (key->getID() < current->key->getID())
			{
				isLeft = true;
				current = current->left;
			}
			else
			{
				isLeft = false;
				current = current->left;
			}
		}
		//Found node to be deleted

		//LEAF
		if (current->left == nullptr && current->right == nullptr)
		{
			if (current == root)
			{
				current = nullptr;
				parent = nullptr;
				root = nullptr;
			}
			else if (isLeft)
			{
				parent->left = nullptr;
			}
			else
			{
				parent->right = nullptr;
			}
		}

		//One Child Left
		else if (current->right == nullptr)
		{
			if (current == root)
			{
				root = current->left;
			}
			else if(isLeft)
			{
				parent->left = current->left;
			}
			else
			{
				parent->right = current->left;
			}

		}

		//One Child Right
		else if (current->left == nullptr)
		{
			if (current == root)
			{
				root = current->right;
			}
			else if (isLeft)
			{
				parent->left = current->right;
			}
			else
			{
				parent->right = current->right;
			}

		}

		else
		{
			TreeNode<T>* successor = BST<T>::getSuccessor(current);

			if (current == root)
			{
				root = successor;

			}
			else if (isLeft)
			{
				parent->left = successor;
			}
			else
			{
				parent->right = successor;
			}

			successor->left = current->left;
			current->left = nullptr;
			current->right = nullptr;
			delete current;
		}
	}
	return true;
}

//Prints all students recursiveley
template<class T>
void PersonTree<T>::printS(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	printS(node->left);
	cout << "\n" << endl;
	cout << "Student ID: " << node->key->getID() << endl;
	cout << "Student Name: " << node->key->getName() << endl;
	cout << "Student Grade Level: " << node->key->getRank() << endl;
	cout << "Student Major: " << node->key->getMajor() << endl;
	cout << "Student GPA: " << node->key->getGPA() << endl;
	cout << "Student Advisor ID: " << node->key->getAdvisorID() << endl;
	printS(node->right);
}

//Function to print students
template<class T>
void PersonTree<T>::printStudents()
{
	if (isEmpty())
	{
		cout << "There are no students in the database!" << endl;
	}
	else
	{
		TreeNode<T>* node = root;
		printS(node);
	}

}

template<class T>
bool PersonTree<T>::isEmpty()
{
	return (root == nullptr);
}

template<class T>
TreeNode<T>* PersonTree<T>::returnPerson(int ID)
{
	TreeNode<T>* current = root;
	while(true)
	{
		if(current->key->getID() == ID)
		{
			break;
		}
		else if (ID < current->key->getID())
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return current;

}

//Prints all the faculty members recursively in order
template<class T>
void PersonTree<T>::printF(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	printF(node->left);
	cout << "\n" << endl;
	cout << "Faculty ID: " << node->key->getID() << endl;
	cout << "Faculty Name: " << node->key->getName() << endl;
	cout << "Faculty Rank: " << node->key->getRank() << endl;
	cout << "Faculty Department: " << node->key->getDepartment() << endl;
	cout << "Faculty Advisees ID's: " << endl;
	node->key->printAdvisees();
	printF(node->right);
}

//Prints all the faculty members
template<class T>
void PersonTree<T>::printFaculty()
{
	if (isEmpty())
	{
		cout << "There are no faculty memebers in the database!" << endl;
	}
	else
	{
		TreeNode<T>* node = root;
		printF(node);
	}

}


#endif
