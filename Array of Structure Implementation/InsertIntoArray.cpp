#include "main.h"

//find arraySize global variable and tutor array from another file
extern Tutor* tutor;
extern int arraySize;

void InsertIntoArray(int tutID, string tutName, string dateJoin, string dateTerm,
	double hrlyRate, string phone, string address, int tcCode, string tcName,
	int subjCode, string subjName, int rating)
{
	//Add tutor attributes to array	
	tutor[arraySize].tutID = tutID;
	tutor[arraySize].tutName = tutName;
	tutor[arraySize].dateJoin = dateJoin;
	tutor[arraySize].dateTerm = dateTerm;
	tutor[arraySize].hrlyRate = hrlyRate;
	tutor[arraySize].phone = phone;
	tutor[arraySize].address = address;
	tutor[arraySize].tcCode = tcCode;
	tutor[arraySize].tcName = tcName;
	tutor[arraySize].subjCode = subjCode;
	tutor[arraySize].subjName = subjName;
	tutor[arraySize].rating = rating;

	::arraySize++;//increase array size
	
	return;
}

