//File name: sequence.h
//Author: Alex Feener
// CSCI 3110 lab5-feener
//Purpose: this is the parent class for the sequence database program

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <iostream>

using namespace std;

class baseSequence{
public:
	//appropriate constructors
	baseSequence( );
	baseSequence( string labelIn, int idIn, string seqIn, int lengthIn);
	virtual ~baseSequence() { };
	
	//getters and setters
	string getLabel( ) { return label; };
	int getID( ) { return accessionID; };
	string getSeq( ) { return sequence; };
	int getLength( ) { return seqLength; };

	void setLabel( string labelIn) { label = labelIn; };
	void setID( int idIn) { accessionID = idIn; };
	void setSeq( string seqIn) { sequence = seqIn; };
	void setLength( int lengthIn) { seqLength = lengthIn; };
	
	//get key method to account for using hash tables
	int getKey(){
		int key = 0;
		for( unsigned i = 0; i < label.length(); i++){
			key += label[i];
		}
		return key;
	}

	// *** pure virtual method ***
	virtual void print() = 0;

protected:
	string label;		//label
	int accessionID;	//Unique accession ID
	string sequence;	//sequence
	int seqLength;		//sequence length
};
#endif