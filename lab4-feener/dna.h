//File name: dna.h
//Author: Alex Feener
// CSCI 3110 lab4-feener
//Purpose: this is the specification file for the DNA class 

#ifndef DNA_H	//include guards
#define DNA_H

#include <string>
#include <fstream>
#include "sequence.h"

using namespace std;

class DNA : public baseSequence{
public:
	DNA();	//default constructor
	~DNA() { }; //destructor

	//setters ( mutators) allow the client to modify each data member
	void setIndex( int indexIn) { index = indexIn; };

	//getters ( accessors) allow a client to have access to each data member
	int getIndex() const { return index;} ;

	//overloaded << operator
	friend ostream& operator<<( ostream& myout, /*const*/ DNA& rhs);
	//overloaded >> operator
	friend istream& operator>>( istream& myin, /*const*/ DNA* rhs);
	// *** polymorphic method ***
	void print( );	//prints the given information

private:
	int index;			//Index of the coding region (-1 if not applicable)
};
#endif