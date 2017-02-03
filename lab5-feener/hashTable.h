//File name:
//Author: Alex Feener
// CSCI 3110 lab5-feener
//Purpose: This is the specification file for the templated HashTable class

//This templated class should store pointers to objects that have a getKey() method. Objects need to be inserted and searched for based on this key value.
/*
Additionally, use separate chaining to resolve collisions, adding new items onto the front of the chain.
This class needs public methods to support adding, removing and finding stored objects.
For each deletion and find (or attempt to delete or find), print out the number of nodes visited and the load factor. 
Finally, this class needs a hash function (you will be graded on your choice of hash functions and if it meets the requirements for a good hash function).
*/


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

//These numbers given in Dr. Hyrum Carroll's video Hashing: Introduction
//MTSU CSCI 3110-001
//Donald Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching, Addison-Wesley, 1973.
const int MULTIPLIER = 25173;
const int ADDEND = 13849;
const int MODULO = 65536;

template <typename T>
class HashTable{
public:
	HashTable( );
	HashTable( int givenSize);
	
	//getters and setters
	double getLoadFactor() { return loadFactor; };
	void setLoadFactor( double alphaIn){ loadFactor = alphaIn; };
	double getSize() { return currSize; };
	void setSize( double sizeIn){ currSize = sizeIn; };
	int getCount() { return hashCount; };
	void setCount( int countIn){ hashCount = countIn; };
	//add
	void insert(T* item);
	
	//remove
	void obliterate( string label);

	//find
	typename <> T* HashTable<T>::find( string label);

	//print number of nodes visited and load factor alpha when using find
	void print( string label);

	int hashFunction( string label);
	int hashFunction( int label);

private:
	list<T*>* myTable;		//list<T*> is the type, * is signifying an array. (int*)
	double loadFactor;		//load factor alpha 
	int currSize;			//size of the hash table
	int hashCount;			//keeps track of how many items are currently stored in the hash table
	int visitCount;			//keeps track of nodes visited in find function
};
#endif

//File name: hashTable.cpp
//Author: Alex Feener
// CSCI 311 lab5-feener
//Purpose: This is the implementation for the templated HashTable class

//default constructor
template<typename T>
HashTable<T>::HashTable(){
	loadFactor = 0.0;
	currSize = 0;
	hashCount = 0;
}

//constructor that sets the size
template <typename T>
HashTable<T>::HashTable( int givenSize){
	loadFactor = 0.0;
	currSize = givenSize; //find out the size from file and set it here
	hashCount = 0;
	
	myTable = new list<T*>[givenSize];
	if( myTable == NULL){
		cout << "Something went wrong: memory was not allocated correctly" << endl;
	}
}
 
//hash function -- turns a string into an int
template <typename T>
int HashTable<T>::hashFunction( string label){
//This formula was given in Dr. Hyrum Carroll's video Hashing: Introduction
//MTSU CSCI 3110-001
//Donald Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching, Addison-Wesley, 1973.
	int key = 0;
		for( unsigned i = 0; i < label.length(); i++){
			key += label[i];
		}
	
	int randomInt;
	
	randomInt = ((MULTIPLIER * key) + ADDEND) % 65536;
	return randomInt % currSize;
}
template <typename T>
int HashTable<T>::hashFunction( int label){
//This formula was given in Dr. Hyrum Carroll's video Hashing: Introduction
//MTSU CSCI 3110-001
//Donald Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching, Addison-Wesley, 1973.
	label = ((MULTIPLIER * label) + ADDEND) % 65536;
	return label % currSize;
}

//inserts item into hash list using hash function to determine the correct position
	//push_front()
template <typename T>
void HashTable<T>::insert( T* item){
	int tablePos = hashFunction( item->getKey() );
	myTable[tablePos].push_front( item);
	hashCount++;
	loadFactor = (double)hashCount/currSize;
	cout << "Load factor: " << loadFactor << endl;
	cout << endl;
}

//searches the hash table for object with specified label. returns a pointer to that item if found, if not found returs NULL
template <typename T>
typename <> T* HashTable<T>::find( string label){
	int tablePos = hashFunction( label);
	typename list<T*>::iterator iter;
	visitCount = 0;			//reset visitCount

	for( iter = myTable[tablePos].begin(); iter != myTable[tablePos].end(); iter++){
		if((*iter)->getLabel() == label){
			return (*iter);
		}else{
			visitCount++;	//notes number of nodes visited before item is found
		}
	}
	//if iter goes through entire list[tablePos], item is not found, so returns NULL
	return NULL;
}

//obliterate searches hash table for object with specified label. if found, item is removed from the table
template <typename T>
void HashTable<T>::obliterate( string label){
	int tablePos = hashFunction( label);
	typename list<T*>::iterator iter;
	visitCount = 0;			//reset visitCount

	for( iter = myTable[tablePos].begin(); iter != myTable[tablePos].end(); iter++){
		if((*iter)->getLabel() == label){
			myTable[hashFunction( label)].erase( iter);	//erases item if found
			cout << visitCount << " items visited by remove()" << endl;
			hashCount--;
			loadFactor = ( double)hashCount/ currSize;
			cout << "Load factor: " << loadFactor << endl;
			return;
		}else{
			visitCount++;	//notes number of nodes visited before item is found
		}
	}

	if( iter == myTable[tablePos].end()){	//item not found
		cout << visitCount << " items visited by remove()" << endl;
		cout << "Can not delete item (" << label << "), NOT found!" << endl;
		return;
	}
}

//print function
template <typename T>
void HashTable<T>::print( string label){
	T* temp;

	temp = find( label);

	if( temp == NULL){		//item not found
		cout << visitCount << " items visited by find()" << endl;
		cout << "Can not find item (" << label << "), NOT found!" << endl;
		return;
	}else{
		cout << visitCount << " items visited by find()" << endl;
		temp->print();
	}
}