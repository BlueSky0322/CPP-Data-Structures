#include "main.h"
#include <string>
#include <sstream>

extern int arraySize;
extern Tutor* tutor;
int recordsToDelete = 0;

int convertDateToDay(string date);
string getCurrentTime();

//function to delete record after 6 months
void deleteAfterTerm()
{
	bool deleted = false;
	int indexToDelete[10];
	int n = 0;
	int opt;
	
	cout << endl << endl << "Checking if any tutor has been terminated for more than 6 months..." << endl;
	int currentDate = convertDateToDay(getCurrentTime()); //store current date as days
	for (int i = 0; i < arraySize; i++)//go through array
	{
		int dateTerm = convertDateToDay(tutor[i].dateTerm); //store date of termination as days
		if ((dateTerm + 180) < currentDate)//if date is 6 months ago
		{
			cout << "Found a tutor that has been terminated for more than 6 months!" << endl;
			cout << endl << "Tutor Name: " << tutor[i].tutName << endl;
			cout << "Tutor ID: " << tutor[i].tutID << endl;
			cout << "Tutor Tuition Centre: " << tutor[i].tcName << endl;
			cout << endl << "This record should be deleted. Would you like to: " << endl;
			
			do
			{
				cout << "1. Confirm deletion." << endl
					<< "2. Cancel deletion." << endl << "Option: ";
				cin >> opt;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (opt != 1 && opt != 2);

			if (opt == 1)
			{
				cout << "Deletion successful. " << endl << endl;
				indexToDelete[n++] = i;
				deleted = true;
			}
			else if (opt == 2)
			{
				cout << "Deletion cancelled." << endl << endl;
				deleted = false;
			}
			else
				return;
		}
	}
	
	int indexCounter = 0;
	for (int k = 0; k < n; k++)//go through array
	{
		int j = k - indexCounter;
		//all elemets after the item to delete is shifted to the left
		while (j < arraySize - 1)
		{
			tutor[j] = tutor[j + 1];
			j++;

		}
		indexCounter++;
		::arraySize--;
	}

	if (!deleted)
		cout << "No other tutor has been terminated for more than 6 months!" << endl;
}

//function to convert date string to int
int convertDateToDay(string date)
{		
	int day, month, year;
	stringstream ss(date);
	ss >> day;
	ss.ignore();
	ss >> month;
	ss.ignore();
	ss >> year;
	return year * 365 + month * 30 + day;
}

//function to get current time
string getCurrentTime()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	stringstream ss;
	ss << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900;
	return ss.str();
}


