#include <iostream>

using namespace std;

//Function prototypes
void sortID();
void sortHourlyRate();
void sortRating();

void sortMenu()
{
	int opt = 0;

	cout << "--SORT MENU--" << endl;
	cout << "Please choose an option to proceed" << endl;
	cout << "1. Sort by Tutor ID in ascending order  " << endl
		<< "2. Sort by Tutors Hourly Pay Rate in ascending order " << endl
		<< "3. Sort by Tutors Overall Performance in ascending order" << endl 
		<< "4. Exit" << endl << endl;

	//Get choice from user
	do
	{
		cout << "Option: ";
		cin >> opt;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (opt < 1 || opt > 3);

	//Direct admin to further functionalities according to their choice
	switch (opt)
	{
	case 1:
		sortID();
		break;
	case 2:
		sortHourlyRate();
		break;
	case 3:
		sortRating();
		break;
	case 4:
		cout << "Have a good day! Bye bye!";
		return;
	default:
		cout << "Invalid Option!";
	}

	return;
}