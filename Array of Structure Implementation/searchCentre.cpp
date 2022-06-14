#include "main.h"
#include <string>
#include <algorithm>

//find arraySize global variable and tutor array from another file
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
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
	for_each(centre.begin(), centre.end(), [](char& c) {c = ::tolower(c); });
	
	cout << "ID\tName\tJoined\t\tTerminated\tRate\tPhone\t\tAddress\t\t\tCentre Code\tCentre Name\tSubject Code\tSubject Name\tRating" << endl << endl;
	//LINEAR SEARCH
	for (int i = 0; i < arraySize; i++)//Traverse through array
	{
		if (tutor[i].tcName == centre)//if centre name matches print out details
		{
			cout << tutor[i].tutID << "\t" << tutor[i].tutName << "\t" << tutor[i].dateJoin << "\t" << tutor[i].dateTerm
				<< "\t" << tutor[i].hrlyRate << "\t" << tutor[i].phone << "\t" << tutor[i].address << "\t" << tutor[i].tcCode
				<< "\t" << tutor[i].tcName << "\t" << tutor[i].subjCode << "\t\t" << tutor[i].subjName << "\t\t" << tutor[i].rating << endl;
		}
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