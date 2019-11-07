#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DblLinkedList
{
	public:
		DLL()
		{
			size = 0;
			front = NULL;
			back = NULL;
		}

		~DblLinkedList()
		{

		};

		void insertBack(T a)
		{
			ListNode<T> *node = new ListNode<T>(a);

			//check if list is empty
			if (size == 0)
			{
				front = node;
			}

			else
			{
				back->next = node;
				node->prev = back;
			}

			back = node;
			++size;
		}

		T removeFront()
		{
		    if (!isEmpty())
		    {
				ListNode<T> *oldFront = front;

			    T oldData = oldFront->data;

			  //check if list has only 1 item
				if (front->next == NULL)
				{
			        front = NULL;
			        back = NULL;
				}

			  //list has multiple items
				else
				{
					front->next->prev = NULL;

			        front = front->next;
				}

				delete oldFront;

				size--;

				return oldData;
		    }

			else
			{
				return T();
			}
		}

		void removeAt(int pos)
		{
			int index = 0;
			ListNode *current = front;
			ListNode *previous = front;

			while (index != pos)
			{
				previous = current;
				current = current->next;
				++index;
			}

			previous->next = current->next;
			current->next->previous = previous;
			current->next = NULL;
			current->previous = NULL;
			current->data = NULL;

			size--;
			delete current;
		}

		T getFront()
		{
			return front->data;
		}

		void printList()
		{
			ListNode<T> *current = front;

			while (true)
			{
				if (current->next == NULL)
				{
					break;
				}

				cout << current->data << ", ";
				current = current->next;
			}
		}

		unsigned int getSize()
		{
			return size;
		}

        bool isEmpty()
		{
		    return (size == 0);
		}

		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;
};
