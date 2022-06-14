#include "main.h"

//Find head and tail global variables in other files
extern Tutor* head;
extern Tutor* tail;

//Function prototypes
void displayAll();
void displayIndv();

void sortRating()
{
	if (head == NULL)//Empty list
	{
		cout << "Empty List. Nothing to sort." << endl;
	}
	else if (head->nextAddress == NULL)//Only 1 node in list
	{
		displayAll();
	}
	else if (head->nextAddress->nextAddress == NULL)//Only 2 nodes in list
	{
		if (tail->rating < head->rating)
		{
			tail->nextAddress = head;
			head->prevAddress = tail;
			tail->prevAddress = NULL;
			head->nextAddress = NULL;
			head = tail;
			tail = head->nextAddress;
		}
		displayIndv();
	}
	else//many nodes in list
	{
		Tutor* current = head->nextAddress;
		Tutor* nextToSort = NULL;

		//INSERTION SORT
		while (current != NULL)//Traverse through linked list
		{
			nextToSort = current->nextAddress;//Store next node in line

			//while hourly rate less than previous node AND head not reached, keep swapping
			while ((current->prevAddress != NULL) && (current->rating < current->prevAddress->rating))
			{
				if (current->prevAddress == head)//swapping with head
				{
					head->nextAddress = current->nextAddress;
					current->nextAddress->prevAddress = head;
					current->prevAddress = NULL;
					current->nextAddress = head;
					head->prevAddress = current;
					head = current;
				}
				else if (current == tail)//tail and swapping with previous node
				{

					current->prevAddress->prevAddress->nextAddress = current;
					current->nextAddress = current->prevAddress;
					current->prevAddress->nextAddress = NULL;
					current->prevAddress = current->prevAddress->prevAddress;
					current->nextAddress->prevAddress = current;
					tail = current->nextAddress;
				}
				else//Nodes in between head and tail
				{
					current->prevAddress->prevAddress->nextAddress = current;
					current->prevAddress->nextAddress = current->nextAddress;
					current->nextAddress = current->prevAddress;
					current->nextAddress->prevAddress = current->prevAddress;
					current->prevAddress = current->prevAddress->prevAddress;
					current->nextAddress->prevAddress = current;
				}
			}
			current = nextToSort;
		}
		//Display tutors one by one
		displayIndv();
	}
	return;
}