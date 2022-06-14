#include "main.h"

//find arraySize global variable and tutor array from other files
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
void login();

void displayIndv()
{	
	int opt = 0;
	int i = 0;

	while(i < arraySize)
	{
		system("cls");//clear screen before printing tutors details
		cout << "Tutor ID: " << tutor[i].tutID << endl;
		cout << "Tutor Name: " << tutor[i].tutName << endl;
		cout << "Date Joined: " << tutor[i].dateJoin << endl;
		cout << "Date Terminated: " << tutor[i].dateTerm << endl;
		cout << "Hourly Rate: " << tutor[i].hrlyRate << endl;
		cout << "Phone: " << tutor[i].phone << endl;
		cout << "Address: " << tutor[i].address << endl;
		cout << "Tuition Centre Code: " << tutor[i].tcCode << endl;
		cout << "Tuition Centre Name: " << tutor[i].tcName << endl;
		cout << "Subject Code: " << tutor[i].subjCode << endl;
		cout << "Subject Name: " << tutor[i].subjName << endl;
		cout << "Rating: " << tutor[i].rating << endl << endl;

		//Get user choice
		do
		{
			cout << "Enter 1 for previous, 2 for next, and 3 to perform other functions, and 4 to exit. Option: ";
			cin >> opt;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (opt < 1 || opt > 4);

		if (opt == 1)//User wants to go back
		{
			if (i == 0)//If first item in array, prevent back
			{
				cout << "This is first item in list. Back not allowed." << endl;
				do
				{
					cout << "Enter 2 for next, and 3 for other functions and 4 to exit. Option: ";
					cin >> opt;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (opt != 2 && opt != 3 && opt != 4);
				if (opt == 2)//Allow user to go forward
				{
					i++;
				}
				else if (opt == 3)//User wants to perform other functions
				{
					login();
					return;
				}
				else//User wants to exit
				{
					return;
				}
			}
			else//Current item is not first, go back
			{
				i--;
			}
		}
		else if (opt == 2)//User wants to go next node
		{
			if (i == arraySize - 1)//if last item in array, prevent forward
			{
				cout << "This is last item in list. Next not allowed." << endl;
				do
				{
					cout << "Enter 1 for previous and 3 to perform other functions and 4 to exit. Option: ";
					cin >> opt;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} while (opt != 1 && opt != 3 && opt != 4);
				if (opt == 1)//Allow user to go to previous item
				{
					i--;
				}
				else if (opt == 3)//Perform other functions
				{
					login();
					return;
				}
				else//Exit
				{
					return;
				}
			}
			else//Current node is not last item, go forward
			{
				i++;
			}
		}
		else if (opt == 3)//User wants to perform other functions
		{
			login();
			return;
		}
		else//User wants to exit
		{
			cout << "Thank you, bye bye.";
			return;
		}
	}
}