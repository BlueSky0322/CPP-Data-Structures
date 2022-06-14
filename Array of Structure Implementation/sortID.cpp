#include "main.h"

//find arraySize global variable and tutor array from another file
extern int arraySize;
extern Tutor* tutor;

//Function prototypes
void displayIndv();
void displayAll();

void sortID()
{
	if (tutor[0].tutID == 0)//Empty array
	{
		cout << "Empty List. Nothing to sort." << endl;
	}
	else if (tutor[1].tutID == 0)//Only 1 item in array
	{
		displayAll();
	}	
	else//many items in array
	{
		Tutor* temp = new Tutor[1];//create temp array for swapping
		int i;
		int j = 0;

		//INSERTION SORT
		for (i = 1; i < arraySize; i++)
		{
			j = i;
			//while ID less than previous struct AND , keep swapping
			while ((j > 0) && (tutor[j - 1].tutID > tutor[j].tutID))
			{				
				temp[0] = tutor[j - 1];
				tutor[j - 1] = tutor[j];
				tutor[j] = temp[0];
				j = j - 1;
			}			
		}
		displayIndv();
	}
	return;
}