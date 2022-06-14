#include "main.h"
#include <string>
#include <sstream>


int recordsToDelete = 0;
extern Tutor* head;
extern Tutor* tail;


int convertDateToDay(string date);
string getCurrentTime();

//function to delete record after 6 months
void deleteAfterTerm()
{
	Tutor* current = head;
	bool deleted = false;
	int opt;

	cout << endl << endl << "Checking if any tutor has been terminated for more than 6 months..." << endl;
	int currentDate = convertDateToDay(getCurrentTime());
	while (current != NULL)//go through array
	{
		int dateTerm = convertDateToDay(current->dateTerm); //store date of termination as days
		if ((dateTerm + 180) < currentDate)//if date is 6 months ago
		{
			cout << "Found a tutor that has been terminated for more than 6 months!" << endl;
			cout << endl << "Tutor Name: " << current->tutName << endl;
			cout << "Tutor ID: " << current->tutID << endl;
			cout << "Tutor Tuition Centre: " << current->tcName << endl;
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
				//Tutor* temp = current;
				if (current == head)//Situation 1: User wants to delete head
				{
					head = head->nextAddress;

					if (head == NULL)//1.1: No more nodes in list 
					{
						tail = NULL;
					}
					else//1.2: There are other nodes in list
					{
						head->prevAddress = NULL;
					}
					cout << "Tutor deleted." << endl;
					delete current;
				}
				else if (current == tail)//Situation 2: User wants to delete tail
				{
					tail = tail->prevAddress;

					if (tail == NULL)//2.1: No more nodes in list 
					{
						head = NULL;
					}
					else//2.2: There are other nodes in list
					{
						tail->nextAddress = NULL;
					}
					cout << "Tutor deleted" << endl;
					delete current;
				}
				else//Situation 3: Middle position
				{
					current->prevAddress->nextAddress = current->nextAddress;
					current->nextAddress->prevAddress = current->prevAddress;
					cout << "Tutor deleted." << endl;
					delete current;
					return;
				}
			}
			else if (opt == 2)
			{
				cout << "Deletion cancelled." << endl << endl;
				deleted = false;
			
			}
			else
				return;
		}
		current = current->nextAddress;
	}


	if (!deleted)
	{
		cout << "No other tutor has been terminated for more than 6 months!" << endl;
	}

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
	//month = (month + 9) % 12;
	//year = year - month / 10;
	return year * 365 + month * 30 + day;
	//return 365 * year + year / 4 - year / 100 + year / 400 + (month * 306 + 5) / 10 + (day - 1);
}

string getCurrentTime()
{
	time_t t = time(0);
	struct tm* now = localtime(&t);
	stringstream ss;
	ss << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900;
	return ss.str();
}