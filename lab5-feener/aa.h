//File name: aa.h
//Author: Alex Feener
// CSCI 3110 lab5-feener
//Purpose: this is the specification file for the AA class 

#ifndef AA_H	//include guards
#define AA_H

#include <string>
#include <fstream>
#include "sequence.h"

using namespace std;

class AA : public baseSequence{
public:
	AA();	//default constructor
	~AA() { };	//destructor

	//setters ( mutators) allow the client to modify each data member
	void setORF( int orfIn) { orf = orfIn; };

	//getters ( accessors) allow a client to have access to each data member
	int getORF() const { return orf; };
	
	//overloaded << operator
	friend ostream& operator<<( ostream& myout, /*const*/ AA& rhs);
	//overloaded >> operator
	friend istream& operator>>( istream& myin, /*const*/ AA* rhs);
	// *** polymorphic method ***
	void print( );	//prints the given information

private:
	int orf;			//Open reading frame for the corresponding DNA sequence: {3-, -2, -1, 0, 1, 2}
};
#endif