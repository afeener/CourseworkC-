//File name: rna.h
//Author: Alex Feener
// CSCI 3110 lab4-feener
//Purpose: this is the specification file for the RNA class 

#ifndef RNA_H	//include guards
#define RNA_H

#include <string>
#include <fstream>
#include "sequence.h"

enum Type{ MRNA, RRNA, TRNA, ERROR};

using namespace std;

class RNA : public baseSequence{
public:
		
	RNA();	//default constructor
	~RNA() { };	//destructor
	//setters ( mutators) allow the client to modify each data member
	void setType( string typeIn);

	//getters ( accessors) allow a client to have access to each data member
	int getType() const { return rnaType; };

	//overloaded << operator
	friend ostream& operator<<( ostream& myout, /*const*/ RNA& rhs);
	//overloaded >> operator
	friend istream& operator>>( istream& myin, /*const*/ RNA* rhs);
	// *** polymorphic method ***
	void print( );	//prints the given information

private:
	Type rnaType;		// enum type of rna: mRNA, rRNA, or tRNA
};
#endif