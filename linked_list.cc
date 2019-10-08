//Project one 
//Implentation File for LinkedList class
// Author: Dylan Wright || Email: dw437013@ohio.edu

// Destructor //
template <class T>
LinkedList<T>::~LinkedList()
{
  while (head != NULL)
  {
	ListNode* tmp;  
    tmp = head;
    delete tmp;
    head = head-> next;
  }
}

//Adds a node containing data to the front of the linked list
template <class T>
void LinkedList<T>::push_front(const T data)
{
  if (head == NULL)
  {
    head = new ListNode(data);
  }
  else
  {
    ListNode* tmp = new ListNode(data);
    tmp -> next = head;
    head = tmp;
  }
}

//Prints what is currently in the list
template <class T>
void LinkedList<T>::print() const
{
  if (head->next == NULL)
  {
    std::cout << head-> data << '\n';
  }
  else
  {
    ListNode* tmp = head;
    while (tmp != NULL)
    {
    	std::cout << tmp -> data << " ";
			tmp = tmp -> next;
    }
			std::cout << '\n';
  }
}

//deletes the leading node of the list
template <class T>
void LinkedList<T>::pop_front()
{
	if (head == NULL)
	{
		//empty list (do nothing)
	}
	else if (head -> next == NULL) // single element list
	{
		delete head;
		head = NULL;
	}
	else
	{
		ListNode* tmp = head;
		head = head -> next;
		delete tmp;
	}
}

//reverses the order of data in the list
template <class T>
void LinkedList<T>::reverse()
{
	if (head == NULL || head->next == NULL)
	{
		//(empty or single node list) -> do nothing
	}
	else
	{
		ListNode* nextNode = head-> next; //holding pointers for the reverseal
		ListNode* tmp;
		ListNode* prev = head;

		prev -> next = NULL; //assigns new end of

		while (nextNode != NULL)
		{
			tmp = nextNode;
			nextNode = nextNode -> next;
			tmp -> next = prev;
			prev = tmp;
		}

		head = prev; //re-assigns the head of the list
	}
}
