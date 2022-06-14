#include "main.h"

//find head global variable from other files
extern Tutor* head;

//Function prototypes
void login();

void displayIndv()
{
	Tutor* current = head;
	int opt = 0;

	while (current != NULL)
	{
		system("cls");//clear screen before printing tutors details
		cout << "Tutor ID: " << current->tutID << endl;
		cout << "Tutor Name: " << current->tutName << endl;
		cout << "Date Joined: " << current->dateJoin << endl;
		cout << "Date Terminated: " << current->dateTerm << endl;
		cout << "Hourly Rate: " << current->hrlyRate << endl;
		cout << "Phone: " << current->phone << endl;
		cout << "Address: " << current->address << endl;
		cout << "Tuition Centre Code: " << current->tcCode << endl;
		cout << "Tuition Centre Name: " << current->tcName << endl;
		cout << "Subject Code: " << current->subjCode << endl;
		cout << "Subject Name: " << current->subjName << endl;
		cout << "Rating: " << current->rating << endl << endl;
		
		//Get user choice
		do
		{
			cout << "Enter 1 for previous, 2 for next, and 3 to perform other functions, and 4 to exit. Option: ";
			cin >> opt;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (opt < 1 || opt > 4);

		if (opt == 1)//User wants to go back
		{
			if (current->prevAddress == NULL)//If current node is head, prevent back
			{
				cout << "This is first item in list. Back not allowed." << endl;
				do
				{
					cout << "Enter 2 for next, and 3 for other functions and 4 to exit. Option: ";
					cin >> opt;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (opt != 2 && opt != 3 && opt != 4);
				if (opt == 2)//Allow user to go next node
				{
					current = current->nextAddress;
				}
				else if (opt == 3)//User wants to perform other functions
				{					
					login();
					return;
				}
				else//User wants to exit
				{
					return;
				}
			}
			else//If current node not head, move to previous node
			{
				current = current->prevAddress;
			}
		}
		else if (opt == 2)//User wants to go next node
		{
			if (current->nextAddress == NULL)//Current node is tail
			{
				//Prevent user from going to next node
				cout << "This is last item in list. Next not allowed." << endl;
				do
				{
					cout << "Enter 1 for previous and 3 to perform other functions and 4 to exit. Option: ";
					cin >> opt;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (opt != 1 && opt != 3 && opt != 4);
				if (opt == 1)//Allow user to go to previous node
				{
					current = current->prevAddress;
				}
				else if (opt == 3)//Perform other functions
				{					
					login();
					return;
				}
				else//Exit
				{
					return;
				}
			}
			else//Current node is not tail, go to next node
			{
				current = current->nextAddress;
			}
		}
		else if (opt == 3)//User wants to perform other functions
		{			
			login();
			return;
		}
		else//User wants to exit
		{
			cout << "Thank you, bye bye.";
			return;
		}		
	}	
}