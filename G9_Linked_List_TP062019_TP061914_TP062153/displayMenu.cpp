#include <iostream>

using namespace std;

//Function prototypes
void displayAll();
void displayIndv();

void displayMenu()
{
	int opt = 0;

	cout << "--DISPLAY MENU--" << endl;
	cout << "Please choose an option to proceed" << endl;
	cout << "1. Display All Records" << endl << "2. Display Page by Page"
		<< endl << "3. Exit" << endl << endl;

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
		displayAll();
		break;
	case 2:
		displayIndv();
		break;
	case 3:
		cout << "Have a good day! Bye bye!";
		return;
	default:
		cout << "Invalid Option!";
	}

	return;
}