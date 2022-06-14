#include "main.h"

//Create new node function
Tutor* CreateNewNode(int tutID, string tutName, string dateJoin, string dateTerm,
	double hrlyRate, string phone, string address, int tcCode, string tcName,
	int subjCode, string subjName, int rating)
{
	//Add tutor attributes to node
	Tutor* newnode = new Tutor;
	newnode->tutID = tutID;
	newnode->tutName = tutName;
	newnode->dateJoin = dateJoin;
	newnode->dateTerm = dateTerm;
	newnode->hrlyRate = hrlyRate;
	newnode->phone = phone;
	newnode->address = address;
	newnode->tcCode = tcCode;
	newnode->tcName = tcName;
	newnode->subjCode = subjCode;
	newnode->subjName = subjName;
	newnode->rating = rating;
	newnode->nextAddress = NULL;
	newnode->prevAddress = NULL;
	return newnode;
}

