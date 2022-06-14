#include "main.h"
#include <string>

//Find arraySize and tutor array from other files
extern int arraySize;
extern Tutor* tutor;

//Function prototype
void login();

void deleteTutor()
{	
	int ID, cont;
	int opt = 0;

	system("cls");

	//Get tutor ID to delete, from user
	do
	{
		cout << "Enter Tutor ID to delete: ";
		cin >> ID;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (ID < 1 || ID > 1000);

	for (int i = 0; i < arraySize; i++)//Go through array
	{
		if (tutor[i].tutID == ID)//if tutor found print details
		{
			cout << "Tutor ID: " << tutor[i].tutID << endl;
			cout << "Tutor Name: " << tutor[i].tutName << endl;
			cout << "Date Terminated: " << tutor[i].dateTerm << endl;

			//Confirmation to delete
			do
			{
				cout << "1. Confirm deletion." << endl
					<< "2. Delete another tutor." << endl
					<< "3. Exit" << endl << "Option: ";
				cin >> opt;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (opt != 1 && opt != 2 && opt != 3);

			if (opt == 1)//Proceed to delete
			{				
				if (i < arraySize - 1)//Situation 1: User wants to delete 1st to second last item
				{
					int j = i;
					//All elemets after the item to delete is shifted to the left
					while (j < arraySize - 1)
					{
						tutor[j] = tutor[j + 1];
						j++;
					}
				}
				arraySize--;
				cout << "Tutor deleted." << endl;
			}
			else if (opt == 2)//User wants to delete another tutor
			{
				deleteTutor();
				return;
			}
			else//User wants to exit
			{
				return;
			}
			cout << "Enter 1 to delete another tutor, 2 to perform other functions, or any other key to exit: ";
			cin >> cont;
			if (cont == 1)//Delete another tutor
			{
				deleteTutor();				
			}
			else if (cont == 2)//back to Login
			{
				cin.clear();
				cin.ignore(100000, '\n');
				login();
			}
			else 
			{
				return;
			}
			return;
		}		
	}
	cout << "Tutor with ID " << ID << " does not exist" << endl;

	cout << "Enter 1 to delete another tutor, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	if (cont == 1)//Delete another record
	{
		deleteTutor();
	}
	else if (cont == 2)//Back to login
	{
		cin.clear();
		cin.ignore(100000, '\n');
		login();
	}
	else//Exit
	{
		return;
	}

	return;
}