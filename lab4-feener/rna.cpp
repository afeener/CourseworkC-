// File name: rna.cpp
// Author: Alex Feener
// CSCI 3110 lab4-feener
// Purpose: this is the implementation file for the RNA class

#include "rna.h"
#include <string>
#include <iostream>

using namespace std;

//default constructor, initializes all fields to 0
RNA::RNA()
	: rnaType( ERROR){
}

//overloaded << operator
ostream& operator<<( ostream& myout, /*const*/ RNA& rhs){
	rhs.print();
	return myout;
}

//overloaded >> operator
istream& operator>>( istream& myin, RNA* rhs){
	string tempLabel, tempSeq, tempType;				//temp variables for getters/setters
	int tempID, tempLength;

	myin >> tempLabel >> tempID >> tempSeq >> tempLength >> tempType;
			(*rhs).setLabel(tempLabel);
			(*rhs).setID(tempID);
			(*rhs).setSeq(tempSeq);
			(*rhs).setLength(tempLength);
			(*rhs).setType(tempType);
	cout << "Note: Adding " << tempID << " ..." << endl;
	cout << endl;
	
	return myin;
}

//sets the type
void RNA::setType(string typeIn){
	if (typeIn == "mRNA"){
	   rnaType = MRNA;
	}else if( typeIn == "rRNA"){
	   rnaType = RRNA;
	}else if( typeIn == "tRNA"){
	   rnaType = TRNA;
	}else{
   rnaType = ERROR;
	}
}
// *** polymorphic method ***
//prints the above information
void RNA::print( )
{	//prints the given information
	cout << "RNA: \tLabel: " << label << "\t ID: " << accessionID << "\tSequence: " << sequence << "\tLength: " << seqLength <<"\tType: ";
		
	switch( rnaType){ 	//stores enum as int
	    case MRNA:
	    cout << "Type: mRNA" << endl;
	    break;
	  case TRNA:
	    cout << "Type: tRNA" << endl;
	    break;
	  case RRNA:
	    cout << "Type: rRNA" << endl;	
	    break;
	  default:
	    cout << "Not an RNA -- something went wrong" << endl;
	    break;
	}

	cout << endl;
}