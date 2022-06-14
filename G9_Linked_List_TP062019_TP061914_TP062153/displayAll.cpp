#include "main.h"

//find head global variable from another file
extern Tutor* head;

//Function prototypes
void login();

void displayAll() 
{
	Tutor* current = head;
	int cont;
	cout << "ID\tName\tJoined\t\tTerminated\tRate\tPhone\t\tAddress\t\t\tCentre Code\tCentre Name\tSubject Code\tSubject Name\tRating" << endl << endl;

	while (current != NULL)//Traverse through linked list and print out tutors details
	{
		cout << current->tutID << "\t" << current->tutName << "\t" << current->dateJoin << "\t" << current->dateTerm
			<< "\t" << current->hrlyRate << "\t" << current->phone << "\t" << current->address << "\t" << current->tcCode 
			<< "\t" << current->tcName << "\t" << current->subjCode << "\t\t" << current->subjName << "\t\t" << current->rating << endl;
		current = current->nextAddress;
	}
	cout << endl << "List is ended here!" << endl << endl;

	cout << "Enter 1 to continue performing other functions or any other key to exit: ";
	cin >> cont;
	if (cont == 1)//back to login screen
	{
		cin.clear();
		cin.ignore(100000, '\n');
		login();
	}
	else//exit
	{
		return;
	}
}