#include "main.h"

extern Tutor* head;//Find head global variable in other files

//Function prototype
void login();

void searchRating()
{
	int rating, cont;

	//get rating from user
	do
	{
		cout << "Enter Tutor rating to search: ";
		cin >> rating;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (rating < 1 || rating > 5);

	Tutor* current = head;
	while (current != NULL)//Traverse through linked list
	{
		//Linear Search
		if (current->rating == rating)//If rating found, print out tutor
		{
			cout << current->tutID << "\t" << current->tutName << "\t" << current->dateJoin << "\t" << current->dateTerm
				<< "\t" << current->hrlyRate << "\t" << current->phone << "\t" << current->address << "\t" << current->tcCode
				<< "\t" << current->tcName << "\t" << current->subjCode << "\t\t" << current->subjName << "\t\t" << current->rating << endl;
		}
		current = current->nextAddress;
	}	

	cout << "Enter 1 to search another rating, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	cin.clear();
	cin.ignore(100000, '\n');
	if (cont == 1)//User chooses to search another centre
	{
		searchRating();
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