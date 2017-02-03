//Author: Alex Feener
//***Code for Bubble sort, Insertion sort, Mergesort, Quicksort, Selection sort, and swap.h provided by Dr. Hyrum Carroll, MTSU
//		for use in lab3-feener, CSCI 3110 Fall 2014
//Purpose: lab3-feener

#include <iostream>
#include <iomanip>
#include "swap.h"
#include <stdlib.h> //for srand
#include <time.h>	// for clock() and CLOCKS_PER_SEC

using namespace std;

//***Code for Bubble sort, Insertion sort, Mergesort, Quicksort, Selection sort, and swap.h provided by Dr. Hyrum Carroll, MTSU
//		for use in lab3-feener, CSCI 3110 Fall 2014
void bubbleSort( int theArray[], int n);
void insertionSort( int theArray[], int n);
void merge( int theArray[],
           int first, int mid, int last, int* tempArray);
void mergesort( int theArray[], int first, int last, int* tempArray);
void choosePivot( int theArray[], int first, int last);
void partition( int theArray[],
               int first, int last, int& pivotIndex);
void quicksort( int theArray[], int first, int last);
int indexOfLargest( const int theArray[], int size);
void selectionSort( int theArray[], int n);

int main(){
	int n = 1;
	int first = 0;
	int mid = n/2;
	int last = n-1;
	int* theArray; 	//array of random numbers
	int* tempArray;	//tempArray for merge function
	int* initArray;	//initial array so list becomes unsorted before each sort
	clock_t begin, end;
	bool done = false;

	cout << "n \tBubble\tInsert\tMerge\tQuick\tSelect" << endl;

	while(!done){ 
		n = n*10;
		//allocate memory for arrays
			theArray = new int[n];
			tempArray = new int[n];
			initArray = new int[n];
		//for every new, there should be a test
		if( theArray == NULL){
			cout << "ERROR: Memory could not be allocated for theArray" << endl;
			return 1;
		}
			
		if( tempArray == NULL){
			cout << "ERROR: Memory could not be allocated for tempArray" << endl;
			return 1;
		}

		if( initArray == NULL){
			cout << "ERROR: Memory could not be allocated for initArray" << endl;
			return 1;
		}

		srand( unsigned( time( NULL)));
		for( int i = 0; i < n; i++){
			theArray[i] = rand( ) % 100;
		}
	
		for( int i = 0; i < n; i++){ //holds values of original array before sorting occurs
			initArray[i] = theArray[i];
		}
	
		cout << n << "\t";
		begin = clock();
		bubbleSort( theArray, n);
		end = clock();
		cout <<  double( end-begin)/CLOCKS_PER_SEC << "\t";

		//reset theArray to original values
		for( int i = 0; i < n; i++){ 
			theArray[i] = 	initArray[i];
		}

		begin = clock();
		insertionSort( theArray, n);
		end = clock();
		cout << double(end-begin)/CLOCKS_PER_SEC << "\t";

		//reset theArray to original values
		for( int i = 0; i < n; i++){ 
			theArray[i] = initArray[i];
		}

		begin = clock();
		mergesort( theArray, first, last, tempArray);
		end = clock();
		cout << double(end-begin)/CLOCKS_PER_SEC << "\t";
			
		//reset theArray to original values
		for( int i = 0; i < n; i++){ 
			theArray[i] = 	initArray[i];
		}

		begin = clock();
		quicksort( theArray, first, last);
		end = clock();
		cout << double( end-begin)/CLOCKS_PER_SEC << "\t";
			
		//reset theArray to original values
		for( int i = 0; i < n; i++){ 
			theArray[i] = 	initArray[i];
		}

		begin = clock();
		selectionSort( theArray, n);
		end = clock();
		cout << double( end-begin)/CLOCKS_PER_SEC << "\t";
	
		cout << endl;
				
		 // deallocate memory
	    delete [ ] theArray;
		delete [ ] tempArray;
		delete [ ] initArray;

		if(n == 100000)
			done = true;
	}	
	return 0;
}

//***Code for Bubble sort, Insertion sort, Mergesort, Quicksort, Selection sort, and swap.h provided by Dr. Hyrum Carroll, MTSU
//		for use in lab3-feener, CSCI 3110 Fall 2014

/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. */

void bubbleSort(int theArray[], int n){
    bool sorted = false;  // false when swaps occur

    for (int pass = 1; (pass < n) && !sorted; ++pass){
        // Invariant: theArray[n+1-pass..n-1] is sorted
        //            and > theArray[0..n-pass]
        sorted = true;  // assume sorted
        for (int index = 0; index < n - pass; ++index){
            // Invariant: theArray[0..index-1] <= theArray[index]
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex]){
                // exchange items
                swap(theArray[index], theArray[nextIndex]);
                sorted = false;  // signal exchange
            }  // end if
        }  // end for

        // Assertion: theArray[0..n-pass-1] <
        // theArray[n-pass]
    }  // end for
}  // end bubbleSort

/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. */
void insertionSort(int theArray[], int n){
   // unSorted = first index of the unSorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unSorted region

   // initially, sorted region is theArray[0],
   //            unSorted region is theArray[1..n-1];
   // in general, sorted region is
   //             theArray[0..unSorted-1],
   // unSorted region is theArray[unSorted..n-1]

   for (int unSorted = 1; unSorted < n; ++unSorted)
   {  // Invariant: theArray[0..unSorted-1] is sorted

      // find the right position (loc) in
      // theArray[0..unSorted] for theArray[unSorted],
      // which is the first item in the unSorted
      // region; shift, if necessary, to make room
      int nextItem = theArray[unSorted];
      int loc = unSorted;

      for (;(loc > 0) && (theArray[loc-1 ]> nextItem);
            --loc)
         // shift theArray[loc-1] to the right
         theArray[loc] = theArray[loc-1];

      // Assertion: theArray[loc] is where nextItem
      // belongs

      // insert nextItem into sorted region
      theArray[loc] = nextItem;
   }  // end for
}  // end insertionSort

/** Merges two sorted array segments theArray[first..mid] and
 *  theArray[mid+1..last] into one sorted array.
 * @pre first <= mid <= last. The subarrays theArray[first..mid]
 * and theArray[mid+1..last] are each sorted in increasing order.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The beginning of the first segment in theArray.
 * @param mid  The end of the first segement in theArray.  mid + 1
 *        marks the beginning of the second segment.
 * @param last  The last element in the second segment in theArray.
 * @note This function merges the two subarrays into a temporary
 * array and copies the result into the original array theArray. */
void merge(int theArray[],
           int first, int mid, int last, int* tempArray)
{
   // initialize the local indexes to indicate the subarrays
   int first1 = first;       // beginning of first subarray
   int last1  = mid;         // end of first subarray
   int first2 = mid + 1;     // beginning of second subarray
   int last2  = last;        // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;    // next available location in
                          // tempArray
   for (; (first1 <= last1) && (first2 <= last2); ++index)
   {  // Invariant: tempArray[first..index-1] is in order
      if (theArray[first1] < theArray[first2])
      {  tempArray[index] = theArray[first1];
         ++first1;
      }
      else
      {  tempArray[index] = theArray[first2];
         ++first2;
      }  // end if
   }  // end for

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      // Invariant: tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      // Invariant: tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];

   // copy the result back into the original array
   for (index = first; index <= last; ++index){
      theArray[index] = tempArray[index];
   }
}  // end merge

/** sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted in ascending order.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void mergesort(int theArray[], int first, int last, int* tempArray){
    
   if (first < last)
   {  // sort each half
      int mid = (first + last)/2;    // index of midpoint
      // sort left half theArray[first..mid]
      mergesort(theArray, first, mid, tempArray);
      // sort right half theArray[mid+1..last]
      mergesort(theArray, mid+1, last, tempArray);

      // merge the two halves
      merge(theArray, first, mid, last, tempArray);
   }  // end if
}  // end mergesort

/** Chooses a pivot for quicksort's partition algorithm and swaps
 *  it with the first item in an array.
 * @pre theArray[first..last] is an array; first <= last.
 * @post theArray[first] is the pivot.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void choosePivot(int theArray[], int first, int last){
    //cerr << "choosePivot(array, " << first << ", " << last << ")\n";
    int mid = first + (last - first) / 2;
    if( (theArray[first] <= theArray[mid] &&
         theArray[mid] <= theArray[last]) ||
        (theArray[last] <= theArray[mid] &&
         theArray[mid] <= theArray[first]) ){
        // value at mid index is middle of values at first and last indices 
        swap(theArray[first], theArray[mid]);
    }else if( (theArray[first] <= theArray[last] &&
               theArray[last] <= theArray[mid]) ||
              (theArray[mid] <= theArray[last] &&
               theArray[last] <= theArray[first])){
        // value at last index is middle of values
        swap(theArray[first], theArray[last]);
    }
}


/** Partitions an array for quicksort.
 * @pre theArray[first..last] is an array; first <= last.
 * @post Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray.
 * @param pivotIndex  The index of the pivot after partitioning. */
void partition(int theArray[],
               int first, int last, int& pivotIndex){
   // place pivot in theArray[first]
   choosePivot(theArray, first, last);
   int pivot = theArray[first];     // copy pivot

   // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in
                                 // unknown

   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; ++firstUnknown)
   {  // Invariant: theArray[first+1..lastS1] < pivot
      //         theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot)
      {  // item from unknown belongs in S1
         ++lastS1;
         swap(theArray[firstUnknown], theArray[lastS1]);
      }  // end if

      // else item from unknown belongs in S2
   }  // end for

   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}  // end partition

/** sorts the items in an array into ascending order.
 * @pre theArray[first..last] is an array.
 * @post theArray[first..last] is sorted.
 * @param theArray  The given array.
 * @param first  The first element to consider in theArray.
 * @param last  The last element to consider in theArray. */
void quicksort(int theArray[], int first, int last){
    int pivotIndex;

    if( first < last){
        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1);
        quicksort(theArray, pivotIndex+1, last);
    }  // end if
}  // end quicksort

/** Finds the largest item in an array.
 * @pre theArray is an array of size items, size >= 1.
 * @post None.
 * @param theArray  The given array.
 * @param size  The number of elements in theArray.
 * @return The index of the largest item in the array. The
 *         arguments are unchanged. */
int indexOfLargest(const int theArray[], int size)
{
   int indexSoFar = 0;  // index of largest item
                        // found so far
   for (int currentIndex = 1; currentIndex < size;
                              ++currentIndex)
   {  // Invariant: theArray[indexSoFar] >=
      //            theArray[0..currentIndex-1]
     if (theArray[currentIndex] > theArray[indexSoFar])
         indexSoFar = currentIndex;
   }  // end for

   return indexSoFar;  // index of largest item
}  // end indexOfLargest


/** sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post The array theArray is sorted into ascending order; n is
 *       unchanged.
 * @param theArray  The array to sort.
 * @param n  The size of theArray. */
void selectionSort(int theArray[], int n){
   // last = index of the last item in the subarray of
   //        items yet to be sorted,
   // largest = index of the largest item found

   for (int last = n-1; last >= 1; --last)
   {  // Invariant: theArray[last+1..n-1] is sorted and
      // > theArray[0..last]

      // select largest item in theArray[0..last]
      int largest = indexOfLargest(theArray, last+1);

      // swap largest item theArray[largest] with
      // theArray[last]
      swap(theArray[largest], theArray[last]);
   }  // end for
}  // end selectionSort