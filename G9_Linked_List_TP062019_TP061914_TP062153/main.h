#include <iostream>

using namespace std;

struct Tutor
{
	int tutID;
	string tutName;
	string dateJoin;
	string dateTerm;
	double hrlyRate;
	string phone;
	string address;
	int tcCode;
	string tcName;
	int subjCode;
	string subjName;
	int rating;
	Tutor* nextAddress;
	Tutor* prevAddress;
};



