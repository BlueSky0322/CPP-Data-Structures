#include "main.h"
#include <string>
#include <algorithm>//Changing string to lowercase

//Function prototypes
void InsertIntoArray(int, string, string, string, double, string, string,
	int, string, int, string, int);
void login();

void addRecord()
{
	int id, tcCode, subCode, rating;
	int cont = 0;
	string name, dateJoin, dateTerm, phone, address, tcName, subName;
	double hourlyRate;

	//Get Tutor details. ID, Name, Date Joined etc.
	do
	{
		cout << "Enter ID: ";
		cin >> id;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (id < 1 || id > 1000);

	cout << "Enter name: ";
	getline(cin, name);

	cout << "Enter Date Joined: ";
	getline(cin, dateJoin);

	cout << "Enter Termination Date: ";
	getline(cin, dateTerm);

	do
	{
		cout << "Enter Hourly Rate: ";
		cin >> hourlyRate;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (hourlyRate < 0 || hourlyRate > 100);

	cout << "Enter Phone Number: ";
	getline(cin, phone);

	cout << "Enter Address: ";
	getline(cin, address);

	do
	{
		cout << "Enter Tuition Centre Code: ";
		cin >> tcCode;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (tcCode < 0 || tcCode > 10);

	cout << "Enter Tuition Centre Name: ";
	getline(cin, tcName);
	//Change tcName variable to lowercase (thispointer, 2014)
	//thispointer. (2014). coonverting-a-string-to-upper-lower-case-in-c-using-stl-boost-library. 
	//Retrieved June 6, 2022, from thispointer.com: 
	//https://thispointer.com/coonverting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/#:~:text=Convert%20a%20String%20to%20Lower,int%20tolower%20(%20int%20c%20)%3B
	for_each(tcName.begin(), tcName.end(), [](char& c) {c = ::tolower(c); });

	do
	{
		cout << "Enter Subject Code: ";
		cin >> subCode;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (subCode < 0);

	cout << "Enter Subject Name: ";
	getline(cin, subName);

	do
	{
		cout << "Enter Rating: ";
		cin >> rating;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (rating < 1 || rating > 5);

	//Insert to end of array
	InsertIntoArray(id, name, dateJoin, dateTerm, hourlyRate, phone, address,
		tcCode, tcName, subCode, subName, rating);	

	cout << "Tutor Added. Enter 1 to add another tutor, 2 to go back, and any other key to exit: ";
	cin >> cont;
	if (cont == 1)//Add another record
	{
		addRecord();
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