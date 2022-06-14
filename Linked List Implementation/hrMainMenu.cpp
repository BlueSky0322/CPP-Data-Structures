#include <iostream>

using namespace std;

//Function prototypes
void displayMenu();
void searchMenu();
void sortMenu();
void addRecord();
void modifyTutor();
void deleteTutor();

void hrMainMenu()
{
	int opt = 0;

	cout << "--WELCOME TO HR MAIN MENU--" << endl;
	cout << "Please choose an option to proceed" << endl;
	cout << "1. Add a Tutor Record" << endl << "2. Display Tutor Records"
		<< endl << "3. Search Tutor Records" << endl << "4. Sort and Display Tutor Records"
		<< endl << "5. Modify Tutor Records" << endl << "6. Delete Tutor Records" << endl << 
		"7. Exit" << endl << endl;

	//Get choice from HR Manager
	do
	{
		cout << "Option: ";
		cin >> opt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (opt < 1 || opt > 7);

	//Direct HR Manager to further functionalities according to their choice
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
		modifyTutor();
		break;		
	case 6:
		deleteTutor();
		break;
	case 7:
		cout << "Have a good day! Bye bye!";
		return;
	default:
		cout << "Invalid Option!";
		break;
	}

	return;
}