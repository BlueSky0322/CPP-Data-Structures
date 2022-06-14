#include "main.h"

extern Tutor* head;
extern Tutor* tail;

void InsertToLinkedListEnd(Tutor* newnode)
{
	//scenario 1: list is still empty, means head is still empty
	if (head == NULL)
	{
		head = tail = newnode;
	}
	//scenario 2: if list not empty, means add item to the last location
	else
	{		
		newnode->prevAddress = tail;
		tail->nextAddress = newnode;
		tail = newnode;
	}	

	return;
}