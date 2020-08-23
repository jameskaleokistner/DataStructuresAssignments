#ifndef GenDoubleList_H_
	#include <iostream>
	using namespace std;
#define GenDoubleList_H_

template <class T> 
class GenNode
{
	public:
		GenNode();
		GenNode(T data);
		~GenNode();
		GenNode<T>* next;
		GenNode<T>* prev;
		T data;
};

template <class T>
GenNode<T>::GenNode()
{
	data = NULL;
	next = nullptr;
	prev = nullptr;
}

template <class T>
GenNode<T>::GenNode(T data)
{
	this->data = data;
	next = nullptr;
	prev = nullptr;
}

template <class T>
GenNode<T>::~GenNode()
{
}


template <class T> 
class GenDoubleList
{
public:
	GenDoubleList();
	~GenDoubleList();

	void insertFront(T d);
	GenNode<T>* returnFront();
	void insertBack(T d);
	T removeBack();
	T removeFront();
	void printList();
	int find(T d);
	unsigned int getSize();
	GenNode<T>* remove(T d);
	T deletePos(int index);
private:
	GenNode<T>* front;
	GenNode<T>* back;
	unsigned int size;
};

template <class T>
GenDoubleList<T>::GenDoubleList()
{
	front = nullptr;
	back = nullptr;
	size = 0;
}

template <class T>
GenDoubleList<T>::~GenDoubleList()
{
	GenNode<T>* nodePtr = front;
	while (nodePtr != nullptr)
	{
		GenNode<T>* nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template <class T>
unsigned int GenDoubleList<T>::getSize()
{
	return size;
}

template <class T>
void GenDoubleList<T>::printList()
{
	GenNode<T>* current = front;
	while(current != nullptr)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

template <class T>
void GenDoubleList<T>::insertFront(T d)
{
	GenNode <T> *node = new GenNode <T> (d);
	if (size == 0)
	{
		back = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	size++;
}

template <class T>
void GenDoubleList<T>::insertBack(T d)
{
	GenNode<T>* node = new GenNode <T> (d);
	if (size == 0)
	{
		front = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	size++;
}

template <class T>
T GenDoubleList<T>::removeFront()
{
	GenNode<T>* temp = front;
	if(front->next == nullptr)
	{
		back = nullptr;
	}
	else
	{
		front->next->prev = nullptr;
	}
	front = front->next;
	temp->next = nullptr;
	T data = temp->data;
	delete temp;
	size--;
	return data;
}

template <class T>
GenNode<T>* GenDoubleList<T>::returnFront()
{
	return this->front;
}

template <class T>
T GenDoubleList<T>::removeBack()
{
	GenNode<T>* temp = back;
	if(back->prev == nullptr)
	{
		front = nullptr;
	}
	else
	{
		back->prev->next = nullptr;
	}
	back = back->prev;
	temp->prev = nullptr;
	T data = temp->data;
	delete temp;
	size--;
	return data;
}

template <class T>
GenNode<T>* GenDoubleList<T>::remove(T d)
{
	GenNode<T>* current = front;

	while(current->data != d)
	{
		current = current->next;
		if (current == nullptr)
		{
			return nullptr;
		}
	}

	if (current == front)
	{
		front = current->next;
	}
	else
	{
		current->prev->next = current->next;
	}

	if (current == back)
	{
		back = current->prev;
	}
	else
	{
		current->next->prev = current->prev;
	}

	current->next = nullptr;
	current->prev = nullptr;

	size--;
	return current;
}

template <class T>
int GenDoubleList<T>::find(T d)
{
	int idx = -1;
	GenNode<T>* current = front;

	while(current != nullptr)
	{
		++idx;
		if (current->data == d)
		{
			break;
		}
		else
		{
			current = current->next;
		}
	}

	if (current == nullptr)
	{
		idx = -1;
	}

	return idx;
}

template <class T>
T GenDoubleList<T>::deletePos(int index)
{
	int idx = 0;
	GenNode<T>* prev = front;
	GenNode<T>* current = front;

	while(idx != index)
	{
		prev = current;
		current = current->next;
		idx++;
	}

	if (idx == index)
	{
		prev->next = current->next;
		current->next = nullptr;
		T data = current->data;
		size--;

		delete current;
		return data;
	}
}

#endif