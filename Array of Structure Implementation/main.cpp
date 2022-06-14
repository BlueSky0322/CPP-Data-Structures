#include "main.h"

//Function prototypes
void InsertIntoArray(int, string, string, string, double, string, string,
	int, string, int, string, int);
void displayAll();
void deleteAfterTerm();
void login();

Tutor* tutor = new Tutor[60];
int arraySize = 0;

int main()
{
	//3 Pre-defined tutors. Create new node and append to end of list
	InsertIntoArray(5, "Ahmad", "10/06/2015", "29/07/2021", 10, "012-3256410", "No.34, Jalan Ahmad Maula", 1, "best tuition", 1, "Science", 5);
	InsertIntoArray(1, "Ali", "10/06/2015", "29/08/2021", 8, "012-3257530", "No.36, Jalan Abdul Razak", 1, "best tuition", 2, "Maths", 4);
	InsertIntoArray(2, "Abu", "11/07/2015", "29/02/2022", 12, "012-3457530", "No.36, Jalan Abdul Rahman", 1, "best tuition", 2, "Maths", 4);
	
	//Print welcome message and move to login screen
	cout << "*** Welcome to eXcel Tuition Centre ***" << endl;
	login();
	
	deleteAfterTerm();
	return 0;
}