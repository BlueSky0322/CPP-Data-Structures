#include "main.h"
#include <string>

extern Tutor* head;

//Function prototype
void login();

void modifyTutor()
{
	Tutor* current = head;
	int ID, cont;
	int opt = 0;	
	string phone, address;

	system("cls");
	//Get tutor ID to modify
	do
	{
		cout << "Enter Tutor ID to modify: ";
		cin >> ID;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (ID < 1 || ID > 1000);
		
	while (current != NULL)//Traverse through linked list
	{
		if (current->tutID == ID)//If tutor ID matches any nodes....
		{
			cout << "Tutor ID: " << current->tutID << endl;
			cout << "Tutor Name: " << current->tutName << endl;
			cout << "Phone: " << current->phone << endl;
			cout << "Address: " << current->address << endl << endl;

			//Ask user if they wish to modify tutors phone or address
			do
			{
				cout << "1. Modify Phone" << endl << "2. Modify Address" << endl << "Option: ";
				cin >> opt;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (opt != 1 && opt != 2);

			if (opt == 1)//Change tutors phone
			{
				cout << "Enter new phone: ";
				getline(cin, phone);
				current->phone = phone;
				cout << "Tutor ID: " << current->tutID << endl;
				cout << "Tutor Name: " << current->tutName << endl;
				cout << "New Phone: " << current->phone << endl;
				cout << "Address: " << current->address << endl << endl;
			}
			else//Change tutors address
			{
				cout << "Enter new address: ";
				getline(cin, address);
				current->address = address;
				cout << "Tutor ID: " << current->tutID << endl;
				cout << "Tutor Name: " << current->tutName << endl;
				cout << "Phone: " << current->phone << endl;
				cout << "New Address: " << current->address << endl << endl;
			}
			cout << "Enter 1 to modify another tutor, 2 to perform other functions, and any other key to exit: ";
			cin >> cont;			
			if (cont == 1)//User chooses to modify another tutor
			{
				modifyTutor();
			}
			else if (cont == 2)//Send user back to login screen
			{
				cin.clear();
				cin.ignore(100000, '\n');
				login();
				return;
			}
			else
			{
				return;
			}			
		}
		else//Tutor ID does not match tutor ID in node. Continue to next node..
		{
			current = current->nextAddress;
		}
	}
	//Whole list traversed and no such Tutor ID found
	cout << "Tutor with ID " << ID << " does not exist" << endl;

	cout << "Enter 1 to modify another tutor, 2 to perform other functions, and any other key to exit: ";
	cin >> cont;
	if (cont == 1)//User chooses to modify another tutor
	{
		modifyTutor();
	}
	else if (cont == 2)//Send user back to login screen
	{
		cin.clear();
		cin.ignore(100000, '\n');
		login();
	}
	else//Exit
	{
		return;
	}	
}