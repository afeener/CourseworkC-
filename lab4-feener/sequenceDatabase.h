// File name: sequenceDatabase.h
// Author: Alex Feener
// CSCI 3110 lab4-feener
// Purpose: this is the specification file for the sequenceDatabase class

#ifndef SEQUENCEDATABASE_H	//include guards
#define SEQUENCEDATABASE_H


#include "sequence.h"
#include "dna.h"
#include "rna.h"
#include "aa.h"
#include <list>
#include <string>

class SequenceDatabase{
public:
	SequenceDatabase( );		//Default constructor

	void importEntries( string commandsFilename); //method to process commands from a specified file

private:
	list<baseSequence*> sequenceList;
	list<baseSequence*>::iterator iter;
	bool found;
};

#endif