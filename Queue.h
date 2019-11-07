#include <iostream>
#include "ListNode.h"

template <class T>
class Queue
{
	public:
		ListNode<T> *front;
		ListNode<T> *back;
		int size;

		Queue()
		{
			size = 0;
			front = NULL;
			back = NULL;
		}

		~Queue()
		{

		};

		void enqueue(T a)
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

		T dequeue()
		{
		    if (!isEmpty())
		    {
				ListNode<T> *prevFront = front;

			    T prevData = prevFront->data;

			  //check if list only has 1 item
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

				delete prevFront;

				size--;

				return prevData;
		    }

			else
			{
				return T();
			}
		}

		T getFront()
		{
			return front->data;
		}

		T getBack()
		{
			return back->data;
		}

		void printQueue()
		{
			ListNode<T> *current = front;

			while (true)
			{
				if (current == NULL)
				{
					break;
				}

				cout << current->data << endl;
				current = current->next;
			}
		}

		int getSize()
		{
			return size;
		}

    bool isEmpty()
		{
				if(size == 0)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
		}
};
