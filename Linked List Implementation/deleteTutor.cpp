#include "main.h"
#include <string>

extern Tutor* head;
extern Tutor* tail;

//Function prototype
void login();

void deleteTutor()
{
	Tutor* current = head;
	int ID, cont;
	int opt = 0;	

	system("cls");

	//Get tutor ID to delete, from user
	do
	{
		cout << "Enter Tutor ID to delete: ";
		cin >> ID;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (ID < 1 || ID > 1000);

	while (current != NULL)//Traverse through linked list
	{
		if (current->tutID == ID)//If tutor ID of any node matches...
		{
			cout << "Tutor ID: " << current->tutID << endl;
			cout << "Tutor Name: " << current->tutName << endl;
			cout << "Date Terminated: " << current->dateTerm << endl;
			
			//Confirmation to delete
			do
			{
				cout << "1. Confirm deletion." << endl 
					<<"2. Delete another tutor." << endl 
					<< "3. Exit" << endl << "Option: ";
				cin >> opt;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (opt != 1 && opt != 2 && opt != 3);

			if (opt == 1)//Proceed to delete
			{
				Tutor* temp = current;
				if (current == head)//Situation 1: User wants to delete head
				{					
					head = head->nextAddress;

					if (head == NULL)//1.1: No more nodes in list 
					{
						tail = NULL;
					}
					else//1.2: There are other nodes in list
					{
						head->prevAddress = NULL;
					}        
					cout << "Tutor deleted." << endl;
					delete current;  					
				}
				else if (current == tail)//Situation 2: User wants to delete tail
				{        
					tail = tail->prevAddress;

					if (tail == NULL)//2.1: No more nodes in list 
					{
						head = NULL;
					}
					else//2.2: There are other nodes in list
					{
						tail->nextAddress = NULL;
					}
					cout << "Tutor deleted" << endl;
					delete current;        
				}
				else//Situation 3: Middle position
				{
					current->prevAddress->nextAddress = current->nextAddress;
					current->nextAddress->prevAddress = current->prevAddress;
					cout << "Tutor deleted." << endl;
					delete current;					
					return;
				}						
			}		
			else if (opt == 2)//Wrong tutor chosen, delete another tutor
			{
				deleteTutor();
				return;
			}
			else
			{
				return;
			}

			//Ask user if they want to delete more tutors
			cout << "Enter 1 to delete another tutor, 2 to perform other functions, and any other key to exit: ";
			cin >> cont;			
			if (cont == 1)//Delete more tutors
			{
				deleteTutor();
			}
			else if (cont == 2)//Stop deletion. Back to login
			{
				cin.clear();
				cin.ignore(100000, '\n');
				login();
			}
			else
			{
				return;
			}
			return;
		}
		else//If tutor ID of node does not match
		{
			current = current->nextAddress;
		}
	}
	//Traversed through entire linked list and no such Tutor ID found
	cout << "Tutor with ID " << ID << " does not exist" << endl;

	cout << "Enter 1 to delete another tutor, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	if (cont == 1)//Delete another record
	{
		deleteTutor();
	}
	else if (cont == 2)//Back to login
	{
		cin.clear();
		cin.ignore(100000, '\n');
		login();
	}
	else//Exit
	{
		return;
	}

	return;
}