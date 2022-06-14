#include <iostream>

using namespace std;

//Function prototypes
void displayMenu();
void searchMenu();
void sortMenu();
void addRecord();

void adminMainMenu()
{
	int opt = 0;

	cout << "--WELCOME TO ADMIN MAIN MENU--" << endl;
	cout << "Please choose an option to proceed" << endl;
	cout << "1. Add a Tutor Record" << endl << "2. Display Tutor Records"
		<< endl << "3. Search Tutor Records" << endl << "4. Sort and Display Tutor Records"
		<< endl << "5. Exit" << endl << endl;
	
	//Get choice from admin
	do
	{
		cout << "Option: ";
		cin >> opt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (opt < 1 || opt > 5);

	//Direct admin to further functionalities according to their choice
	switch (opt) 
	{
	case 1: 
		addRecord();
		break;
	case 2:
		displayMenu();
		break;
	case 3:
		searchMenu();
		break;
	case 4:
		sortMenu();
		break;
	case 5:
		cout << "Have a good day! Bye bye!";
		return;		
	default:
		cout << "Invalid Option!";
	}

	return;
}