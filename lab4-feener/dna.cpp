// File name: dna.cpp
// Author: Alex Feener
// CSCI 3110 lab4-feener
// Purpose: this is the implementation file for the DNA class

#include "dna.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//default constructor, initializes all fields to 0
DNA::DNA()
	: index(0){
}

//overloaded << operator
ostream& operator<<( ostream& myout, /*const*/ DNA& rhs){
	rhs.print();
	return myout;
}

istream& operator>>( istream& myin, DNA* rhs){
	string tempLabel, tempSeq;				//temp variables for getters/setters
	int tempID, tempLength, tempIndex;		//temp variables for getters/setters

	myin >> tempLabel >> tempID >> tempSeq >> tempLength >> tempIndex;
			(*rhs).setLabel(tempLabel);
			(*rhs).setID(tempID);
			(*rhs).setSeq(tempSeq);
			(*rhs).setLength(tempLength);
			(*rhs).setIndex(tempIndex);
	cout << "Note: Adding " << tempID << " ..." << endl;
	cout << endl;
	
	return myin;
}
// *** polymorphic method ***
//prints the above information
void DNA::print( )
{	//prints the given information
	cout << "DNA: \tLabel: " << label << "\t ID: " << accessionID << "\tSequence: " << sequence << "\tLength: " << seqLength << "\tcDNAStartIndex: " << index << endl;
	cout << endl;
}
