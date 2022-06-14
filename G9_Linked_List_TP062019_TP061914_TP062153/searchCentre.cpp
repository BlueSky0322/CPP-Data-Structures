#include "main.h"
#include <string>
#include <algorithm>

//Find head global variable in other files
extern Tutor* head;

//Function Prototypes
void login();

void searchCentre()
{
	string centre;
	int cont;

	//Get centre from user
	cout << "Enter Centre to search: ";
	getline(cin, centre);		
	//Change tcName variable to lowercase (thispointer, 2014)
	//thispointer. (2014). coonverting-a-string-to-upper-lower-case-in-c-using-stl-boost-library. 
	//Retrieved June 6, 2022, from thispointer.com: 
	//https://thispointer.com/coonverting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/#:~:text=Convert%20a%20String%20to%20Lower,int%20tolower%20(%20int%20c%20)%3B
	for_each(centre.begin(), centre.end(), [](char& c) {c = ::tolower(c);});

	Tutor* current = head;
	//LINEAR SEARCH
	while (current != NULL)//Traverse through linked list
	{		
		if (current->tcName == centre)//If centre matches any node, print out node
		{
			cout << current->tutID << "\t" << current->tutName << "\t" << current->dateJoin << "\t" << current->dateTerm
				<< "\t" << current->hrlyRate << "\t" << current->phone << "\t" << current->address << "\t" << current->tcCode
				<< "\t" << current->tcName << "\t" << current->subjCode << "\t\t" << current->subjName << "\t\t" << current->rating << endl;
		}
		
		current = current->nextAddress;
	}
	
	cout << "Enter 1 to search another centre, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	cin.clear();
	cin.ignore(100000, '\n');
	if (cont == 1)//User chooses to search another centre
	{
		searchCentre();
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