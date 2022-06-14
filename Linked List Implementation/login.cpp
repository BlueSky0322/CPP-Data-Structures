#include <iostream>
#include <string>

using namespace std;

//Function prototypes
void adminMainMenu();
void hrMainMenu();

void login()
{
	int flag = 0;
	string id, pwd;
	cout << "--Kindly Login to continue--" << endl;

	while (flag == 0)
	{		
		//Get username and password from user
		cout << "Enter Username: ";
		cin >> id;		
		cout << "Enter Password: ";
		cin >> pwd;			

		if (id == "admin" && pwd == "admin")//If admin logs in, direct to admin screen
		{
			system("cls");
			adminMainMenu();
			flag = 1;
		}
		else if (id == "hrmanager" && pwd == "hrmanager")//If HR manager logs in, direct to HR manager screen
		{
			system("cls");
			hrMainMenu();
			flag = 1;
		}
		else
		{
			cout << "Incorrect username or password! Please try again." << endl;
		}
	}
		
	return;
}