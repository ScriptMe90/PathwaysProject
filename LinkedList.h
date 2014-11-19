#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	Node()
	{
		next = NULL;
	}

	Node(T dat)
	{
		data = dat;
		next = NULL;
	}


	Node(T dat, Node* n)
	{
		data = dat;
		next = n;
	}


	friend std::ostream& operator<<(std::ostream& os, const Node<T>& l)
	{
		os << l.data << std::endl;
	}

	T data;
	Node<T>* next;
	friend class LinkedList<T>;
};

template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		m_head = NULL;
	}



	LinkedList(const LinkedList& other)
	{
		if (other.m_head != NULL)
		{
			Node<T>* temp = new Node<T>(other.m_head->data);
			Node<T>* head = temp;
			temp->next = NULL;
			Node<T>* temp2 = other.m_head->next;
			while (temp2 != NULL)
			{
				temp->next = new Node<T>(temp2->data);
				temp2 = temp2->next;
				temp = temp->next;
			}
			temp->next = NULL;
			m_head = head;
		}
	}


	LinkedList& operator=(const LinkedList& other)
	{
		//std::cout << "Assignment operator called";
		if (&other == this)
		{
			return *this;
		}

		this->~LinkedList();

		if (other.m_head != NULL)
		{
			Node<T>* temp = other.m_head;
			Node<T>* temp2 = new Node<T>(temp->data);
			Node<T>* head = temp2;

			while (temp->next != NULL)
			{
				temp = temp->next;
				temp2->next = new Node<T>(temp->data);
				temp2 = temp2->next;
				//std::cout << temp->data << " added to the list." << std::endl;
			}
			temp2->next = NULL;
			m_head = head;
			return *this;
		}
	}




	~LinkedList()
	{
		//std::cout << "Destructor called!!" << std::endl;
		if (m_head != NULL)
		{
			Node<T>* temp = m_head;
			while (temp->next != NULL)
			{
				Node<T>* temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
		}
		m_head = NULL;
	}



	bool insert(T item)
	{
		Node<T>* it = new Node<T>(item);
		if (m_head == NULL)
		{
			m_head = it;
			m_head->next = NULL;
			return true;
		}
		else
		{
			if (m_head->data < item)
			{
				Node<T>* curr = m_head->next;
				Node<T>* prev = m_head;
				while (curr != NULL)
				{
					if (curr->data < item)
					{
						curr = curr->next;
						prev = prev->next;
					}
					else if (curr->data > item)
					{
						prev->next = it;
						it->next = curr;
						return true;
					}
					else if (curr->data == item)
					{
						//std::cout << "Duplicate!!" << std::endl;
						return false;
					}
				}

				prev->next = it;
				it->next = NULL;
				return true;
			}
			else if (m_head->data > item)
			{
				it->next = m_head;
				m_head = it;
				return true;
			}
			else
			{
				//std::cout << "Duplicate!!" << std::endl;
				return false;
			}
		}
	}



	bool remove(T item)
	{
		if (m_head == NULL)
		{
			return false;
		}
		Node<T>* temp = m_head;
		Node<T>* temp2 = temp->next;

		if (temp->data == item)
		{
			delete temp;
			m_head = temp2;
			return true;
		}

		while (temp2->next != NULL)
		{
			if (temp2->data == item)
			{
				temp->next = temp2->next;
				delete temp2;
				return true;
			}
			else
			{
				temp = temp->next;
				temp2 = temp2->next;
			}
		}
		return false;
	}


	Node<T>* search(T item)
	{
		if (m_head == NULL)
		{
			return NULL;
		}

		Node<T>* temp = m_head;
		Node<T>* temp2 = temp->next;

		if (temp->data == item)
		{
			return temp;
		}

		while (temp2 != NULL)
		{
			if (temp2->data == item)
			{
				return temp2;
			}
			else
			{
				temp = temp->next;
				temp2 = temp2->next;
			}
		}

		return NULL;
	}



	void printData()
	{
		Node<T>* temp = m_head;
		while (temp != NULL)
		{
			/*
			std::cout << temp->data << std::endl;
			temp = temp->next;*/
		}
	}



	friend std::ostream& operator <<(std::ostream& os, LinkedList& other)
	{
		other.printData();
		return os;
	}


private:
	Node<T>* m_head;
};


#endif // LINKEDLIST_H
