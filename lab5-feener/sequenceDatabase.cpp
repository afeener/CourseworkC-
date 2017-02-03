//File name: sequenceDatabase.cpp
//Author: Alex Feener
// CSCI 3110 lab5-feener
//Purpose: this is the implementation file for the sequenceDatabase class 

#include "sequenceDatabase.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

//default constructor
SequenceDatabase::SequenceDatabase(){ 
}

//method to process commands from a specified file
void SequenceDatabase::importEntries( string commandsFilename) {
	
	fstream myin;
	int buckets;
	char choice;							//Holds the command option
	
	baseSequence* tempDNA = NULL;			//temp variable given variables before assigning/saving
	baseSequence* tempRNA = NULL;
	baseSequence* tempAA = NULL;
	string tempLabel;				//temp variables for getters/setters
	
	myin.open(commandsFilename.c_str() );
	if (!myin)
	{
		cerr << "Unable to open file." << endl;
	}

	myin >> buckets;
	HashTable<baseSequence> myHashTable( buckets);
	
	myin >> choice;
	while ( !myin.eof())		//loop while file has data
	{
		if( choice =='D'){
			DNA* newDNA = new DNA;
			myin >> newDNA;
			baseSequence* tempDNA = newDNA;
			myHashTable.insert( tempDNA);
		}else if( choice == 'R'){
			RNA* newRNA = new RNA;
			myin >> newRNA;
			baseSequence* tempRNA = newRNA;
			myHashTable.insert( newRNA);
		}else if( choice == 'A'){
			AA* newAA = new AA;
			myin >> newAA;
			baseSequence* tempAA = newAA;
			myHashTable.insert( newAA);
		}else if(choice == 'O'){		//obliterate specified entry
			myin >> tempLabel;
			cout << "Note: Obliterating " << tempLabel << " ..." << endl;
			myHashTable.obliterate( tempLabel);
			cout << endl;
		}else if( choice == 'P'){	//print specified entry
			myin >> tempLabel;
		 	cout << "Note: Printing " << tempLabel << " ..." << endl;
			myHashTable.print( tempLabel);
			cout << endl;
		}else if( choice == 'S'){
			cout << "Entries: " << myHashTable.getCount() << endl;
			cout << endl;
		}else{
			cout << "Invalid input" << ": " << choice << endl;
		}
		myin >> choice;
	}
	
	myin.close();	//close any open files

	return;
}