/**
*	@author Drew Fink
*	@date 2021-09-06
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	while(temp != nullptr)
	{
		if(temp->getValue() == value)
		{
			return(true); // If what's at the front is our value, success!
		}
		else
		{
			temp = temp->getNext(); // Otherwise, keep going.
		}
	}
	return(isFound); // This is always false if true hasn't been returned already.
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(!isEmpty()) // If the linked list is empty, you don't need to do anything.
	{
		secondintoLast = m_front; // Start at the front.

		while(secondintoLast->getNext()->getNext() != nullptr) // We need to stop at the end. If the next-next is nullptr, that means we're at the end.
		{
			secondintoLast = secondintoLast->getNext();
		}

		lastNode = secondintoLast->getNext(); // With the way we search using getNext(), we still end up at the second-to-last. So the last node is the next.
		delete lastNode;

		secondintoLast->setNext(nullptr); // We can't actually set lastNode itself as nullptr. That doesn't work. So we settle for this method.
		m_size--;

		return true;
	}

	return(isRemoved); // This will always be false if true hasn't been returned already.
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
