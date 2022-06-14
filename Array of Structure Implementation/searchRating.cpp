#include "main.h"

//find arraySize global variable and tutor array from another file
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
void login();

void searchRating()
{
	int rating, cont;

	//Get ID from user
	do
	{
		cout << "Enter Tutor rating to search: ";
		cin >> rating;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (rating < 1 || rating > 5);

	cout << "ID\tName\tJoined\t\tTerminated\tRate\tPhone\t\tAddress\t\t\tCentre Code\tCentre Name\tSubject Code\tSubject Name\tRating" << endl << endl;
	//LINEAR SEARCH
	for (int i = 0; i < arraySize; i++)//Traverse through array
	{
		if (tutor[i].rating == rating)//if rating matches print out details
		{
			cout << tutor[i].tutID << "\t" << tutor[i].tutName << "\t" << tutor[i].dateJoin << "\t" << tutor[i].dateTerm
				<< "\t" << tutor[i].hrlyRate << "\t" << tutor[i].phone << "\t" << tutor[i].address << "\t" << tutor[i].tcCode
				<< "\t" << tutor[i].tcName << "\t" << tutor[i].subjCode << "\t\t" << tutor[i].subjName << "\t\t" << tutor[i].rating << endl;
		}
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