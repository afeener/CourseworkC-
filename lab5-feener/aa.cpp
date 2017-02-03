// File name: aa.cpp
// Author: Alex Feener
// CSCI 3110 lab5-feener
// Purpose: this is the implementation file for the AA class

#include "aa.h"
#include <string>
#include <iostream>

using namespace std;

//default constructor, initializes all fields to 0
AA::AA()
	: orf(-99) {
}

//overloaded << operator
ostream& operator<<( ostream& myout, /*const*/ AA& rhs){
	rhs.print();
	return myout;
}

//overloaded >> operator
istream& operator>>( istream& myin, AA* rhs){
	string tempLabel, tempSeq;				//temp variables for getters/setters
	int tempID, tempLength, tempORF; 		//temp variables for getters/setters

	myin >> tempLabel >> tempID >> tempSeq >> tempLength >> tempORF;
			(*rhs).setLabel(tempLabel);
			(*rhs).setID(tempID);
			(*rhs).setSeq(tempSeq);
			(*rhs).setLength(tempLength);
			(*rhs).setORF(tempORF);
	cout << "Note: Adding " << tempLabel << " ..." << endl;
//	cout << endl;
	
	return myin;
}
// *** polymorphic method ***
//prints the above information
void AA::print( )
{	//prints the given information
	cout << "AA: \tLabel: " << label << "\t ID: " << accessionID << "\tSequence: " << sequence << "\tLength: " << seqLength << "\tORF: " << orf << endl;
	cout << endl;
}