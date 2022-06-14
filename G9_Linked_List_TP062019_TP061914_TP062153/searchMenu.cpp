#include <iostream>

using namespace std;

//Function prototypes
void searchID();
void searchRating();
void searchCentre();

void searchMenu()
{
	int opt = 0;

	cout << "--SEARCH MENU--" << endl;
	cout << "Please choose an option to proceed" << endl;
	cout << "1. Search a Tutor by Tutor ID " << endl 
		<< "2. Search Tutors by overall performance(Rating)" << endl 
		<< "3. Search Tutors by Centre" << endl << "4. Exit" << endl << endl;

	//Get choice from user
	do
	{
		cout << "Option: ";
		cin >> opt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (opt < 1 || opt > 3);

	//Direct user to further functionalities according to their choice
	switch (opt)
	{
	case 1:
		searchID();
		break;
	case 2:
		searchRating();
		break;
	case 3:
		searchCentre();
		break;
	case 4:
		cout << "Have a good day! Bye bye!";
		return;
	default:
		cout << "Invalid Option!";
	}

	return;
}