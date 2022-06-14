#include "main.h"

//find arraySize global variable and tutor array from another file
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
void login();

void displayAll()
{	
	int cont;

	cout << "ID\tName\tJoined\t\tTerminated\tRate\tPhone\t\tAddress\t\t\tCentre Code\tCentre Name\tSubject Code\tSubject Name\tRating" << endl << endl;
	for (int i = 0; i < arraySize; i++)//Traverse through array and print out tutors details
	{
		cout << tutor[i].tutID << "\t" << tutor[i].tutName << "\t" << tutor[i].dateJoin << "\t" << tutor[i].dateTerm
			<< "\t" << tutor[i].hrlyRate << "\t" << tutor[i].phone << "\t" << tutor[i].address << "\t" << tutor[i].tcCode
			<< "\t" << tutor[i].tcName << "\t" << tutor[i].subjCode << "\t\t" << tutor[i].subjName << "\t\t" << tutor[i].rating << endl;		
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