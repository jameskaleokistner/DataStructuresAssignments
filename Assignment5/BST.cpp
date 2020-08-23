#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(T key);
		virtual ~TreeNode();

		T key;
		TreeNode<T>* left;
		TreeNode<T>* right;
};

template <class T>
TreeNode<T>::TreeNode()
{
	left = nullptr;
	right = nullptr;
}

template <class T>
TreeNode<T>::TreeNode(T k)
{
	left = nullptr;
	right = nullptr;
	this->key = k;
}

template <class T>
TreeNode<T>::~TreeNode()
{
	cout << "\nTree node deleted" << endl;
}

template<class T>
class BST
{
	public:
 		BST();
		~BST();

		//void serialize(FileInput* fp);
		//void deSerialize(FileInput* fp);
		void insert(T key);
		bool contains(T key);
		bool deleteRec(T key); //recursive
		bool isEmpty();
		TreeNode<T>* getSuccessor(TreeNode<T>* d);
		void printTree(); //Iterative
		void recPrint(TreeNode<T>* node); //In-order Traversal recurrsive
		TreeNode<T>* getRoot();
		void deleteTree(TreeNode<T>* node);

	private:
		TreeNode<T>* root;
		
};

template<class T>
BST<T>::BST()
{
	root = nullptr;
}

template<class T>
BST<T>::~BST()
{
	deleteTree(this->root);
}

template<class T>
void BST<T>::deleteTree(TreeNode<T>* node)
{
	if (node)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template<class T>
TreeNode<T>* BST<T>::getRoot()
{
	return this->root;
}

template<class T>
void BST<T>::insert(T key) //iterative
{
	//Check if contains
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

			if(key < current->key)
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
void BST<T>::printTree()
{
	recPrint(root);
}

template<class T>
bool BST<T>::isEmpty()
{
	return (root == nullptr);
}

template<class T>
void BST<T>::recPrint(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	recPrint(node->left);
	//cout << node->key << endl; // for in-order traversal
	recPrint(node->right);
}

template<class T>
bool BST<T>::contains(T key)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		TreeNode<T>* current = root;

		while(current->key != key)
		{
			if(current == nullptr)
			{
				return false;
			}
			if (key < current->key)
			{
				current->left;
			}
			else
			{
				current->right;
			}
		}
	}
	return true;

}

template<class T>
bool BST<T>::deleteRec(T key)
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
		while(current->key != key)
		{
			parent = current;

			if (key < current->key)
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
			TreeNode<T>* successor = getSuccessor(current);

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

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d)
{
	TreeNode<T>* sp = d; //Successor's parent
	TreeNode<T>* successor= d; //Should be all the way left
	TreeNode<T>* current = d->right;

	while (current != nullptr)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}


	if (successor != d-> right)
	{
		sp->left = successor->right;
		successor->right = d->right;
	}

	return successor;
}



