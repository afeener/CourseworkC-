//File name: sequenceDatabase.cpp
//Author: Alex Feener
// CSCI 3110 lab4-feener
//Purpose: this is the implementation file for the SequencingDatabase class 

#include "sequenceDatabase.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

//default constructor
SequenceDatabase::SequenceDatabase() { 
	sequenceList;
}

//method to process commands from a specified file
void SequenceDatabase::importEntries( string commandsFilename) {
	
	fstream myin;
	char choice;							//Holds the command option
	
	baseSequence* tempDNA = NULL;			//temp variable given variables before assigning/saving
	baseSequence* tempRNA = NULL;
	baseSequence* tempAA = NULL;
	string tempLabel, tempSeq;				//temp variables for getters/setters
	int tempID; 
	bool found = false;
	
	myin.open(commandsFilename.c_str() );
	if (!myin)
	{
		cerr << "Unable to open file." << endl;
	}

	myin >> choice;
	while ( !myin.eof())		//loop while file has data
	{
		if( choice =='D'){
			DNA* newDNA = new DNA;
			myin >> newDNA;
			baseSequence* tempDNA = newDNA;
			sequenceList.push_back( newDNA);
		}else if( choice == 'R'){
			RNA* newRNA = new RNA;
			myin >> newRNA;
			baseSequence* tempRNA = newRNA;
			sequenceList.push_back( newRNA);
		}else if( choice == 'A'){
			AA* newAA = new AA;
			myin >> newAA;
			baseSequence* tempAA = newAA;
			sequenceList.push_back( newAA);
		}else if(choice == 'O'){		//obliterate specified entry
			myin >> tempID;
			found = false;
			cout << "Note: Obliterating " << tempID << " ..." << endl;
			//use an iterator to find and obliterate
			if(!sequenceList.empty()){
				for( iter = sequenceList.begin(); iter != sequenceList.end() && found == false; iter++){
					if ( (*iter)->getID() == tempID){	//compare each ID in list to tempID
						found = true;	//item found
						break;			//exit the loop
					}else{
						//do nothing
					}
			}
				if(found == true){	//if tempId matches id of element in list, erase it
					sequenceList.erase(iter);
					cout << endl;
				}else{
					cout << "Can not delete item, (" << tempID << "), NOT found!" << endl;
					cout << endl;
				}
			}
		}else if( choice == 'P'){	//print specified entry
			myin >> tempID;
			found = false;
		 	cout << "Note: Printing " << tempID << " ..." << endl;
			//use an iterator to find and print
			if(!sequenceList.empty()){
				for( iter = sequenceList.begin(); iter != sequenceList.end() && found == false; iter++){
					if ( (*iter)->getID() == tempID){	//compare each ID in list to tempID
						found = true;	//item found
						break;			//exit the loop
					}else{
						//do nothing
					}
			}
				if(found == true){	//if tempId matches id of element in list, print it
					(*iter)->print();
					cout << endl;
				}else{	//item not found, prints error statement
					cout << "Can not find item (" << tempID << ")!" << endl;
					cout << endl;
				}
			}else{	//list is empty, so it can't find the item
				cout << "Can not find item (" << tempID << ")!" << endl;
				cout << endl;
			}

		}else if( choice == 'S'){
			//cout the size of sequence
			cout << "Entries: " << sequenceList.size() << " total" << endl;
			cout << endl;
		}else{
			cout << "Invalid input" << ": " << choice << endl;
		}
		myin >> choice;
	}
	
	myin.close();	//close any open files

	return;
}