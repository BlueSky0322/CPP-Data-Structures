#include "main.h"

//Find head global variable in other files
extern Tutor* head;

//Function Prototype
void login();

void searchID()
{
	int ID, cont;	

	//Get ID from user
	do
	{
		cout << "Enter Tutor ID to search: ";
		cin >> ID;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (ID < 1 || ID > 1000);

	Tutor* current = head;
	//LINEAR SEARCH
	while (current != NULL)//Traverse through linked list
	{		
		if (current->tutID == ID)//if ID matches, print node
		{
			cout << current->tutID << "\t" << current->tutName << "\t" 
				<< current->dateJoin << "\t" << current->dateTerm
				<< "\t" << current->hrlyRate << "\t" << current->phone 
				<< "\t" << current->address << "\t" << current->tcCode
				<< "\t" << current->tcName << "\t" << current->subjCode 
				<< "\t\t" << current->subjName << "\t\t" << current->rating << endl;
		}
		
		current = current->nextAddress;		
	}

	cout << "Enter 1 to search another ID, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	cin.clear();
	cin.ignore(100000, '\n');
	if (cont == 1)//User chooses to search another centre
	{
		searchID();
	}
	else if (cont == 2)//Send user back to login screen
	{
		login();
	}
	else
	{
		return;
	}
	return;
}