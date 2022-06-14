#include "main.h"
#include <string>

//find arraySize global variable and tutor array from another file
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
void login();

void modifyTutor()
{	
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

	for (int i = 0; i < arraySize; i++)//Traverse through array
	{
		if (tutor[i].tutID == ID)//if tutor id matches print some details
		{
			cout << "Tutor ID: " << tutor[i].tutID << endl;
			cout << "Tutor Name: " << tutor[i].tutName << endl;
			cout << "Phone: " << tutor[i].phone << endl;
			cout << "Address: " << tutor[i].address << endl << endl;

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
				tutor[i].phone = phone;
				cout << "Tutor ID: " << tutor[i].tutID << endl;
				cout << "Tutor Name: " << tutor[i].tutName << endl;
				cout << "New Phone: " << tutor[i].phone << endl;
				cout << "Address: " << tutor[i].address << endl << endl;
			}
			else//Change tutors address
			{
				cout << "Enter new address: ";
				getline(cin, address);
				tutor[i].address = address;
				cout << "Tutor ID: " << tutor[i].tutID << endl;
				cout << "Tutor Name: " << tutor[i].tutName << endl;
				cout << "Phone: " << tutor[i].phone << endl;
				cout << "New Address: " << tutor[i].address << endl << endl;
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
			return;
		}		
	}
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