//Author: Alex Feener
//MTSU CSCI 3080
//File: lab2.cpp
//Purpose: Calculate the inverse of a matrix. The dimensions will be 
//	no more than 10X10. The program should first ask for the size
//	(only one dimension because they are square matricies), then
//	read in the matrix. It will then calculate the inverse. The program
//	should print out the inverse matrix.

#include <iostream>

using namespace std;

const int MAX = 10;

//function prototypes
void mainDiag( float initMatrix[][MAX], float newMatrix[][MAX], int sizeOf, int mainPos);

int main(){
	//declare variables
	int sizeOf, mainPos;
	float temp1, temp2;  
	int i, j, k;
	float initMatrix[MAX][MAX];
	float newMatrix[MAX][MAX];
	
	//ask for the size
	cout << "Please input the size of the matrix: ";
	cin >> sizeOf;
	cout << endl;
	
	//read in the matrix
	cout << "Input the " << sizeOf << "X" << sizeOf << " matrix:" << endl;
	
	for(  i = 0; i < sizeOf; i++){
		for(  j = 0; j < sizeOf; j++){
			cin >> initMatrix[i][j];
			if( i == j){
				newMatrix[i][j] = 1;
			} else{
				newMatrix[i][j] = 0;
			}
		}
		
	}

	cout << endl;
	for(i = 0; i < sizeOf;i++){	//outer loop controls main diagonal
		mainPos = i;
		mainDiag(initMatrix, newMatrix, sizeOf, mainPos);	//should divide by [i][i] to get 1 in [i][i]
		for( j = i+1; j< sizeOf; j++){//middle loop should loop through [i][j] to fill in 0s 
			temp1 = initMatrix[j][i]; //value to subtract and multiply

			for( k = 0; k < sizeOf; k++){	//subtract and multiply temp to get 0
				initMatrix[j][k] = initMatrix[j][k]-(temp1*initMatrix[i][k]);
				newMatrix[j][k] = newMatrix[j][k]-(temp1*newMatrix[i][k]);
			}
		}
	}

	for(i = sizeOf-1; i >= 0; i--){	//repeat above, but for elements above main diagonal
		for( j = i-1 ; j >= 0; j--){//middle loop should loop though [i][j] to fill in 0s
			temp2 = initMatrix[j][i];	//value to subtract and multiply
			for(k = 0; k < sizeOf; k++){//subtract and multiply by temp to get 0
				initMatrix[j][k] = initMatrix[j][k]-(temp2*initMatrix[i][k]);
				newMatrix[j][k] = newMatrix[j][k]-(temp2*newMatrix[i][k]);
			}
		}
	}

	cout << "The inverse matrix is: " << endl;
	for( int i = 0; i < sizeOf; i++){
		cout << endl;
		for(int j = 0; j < sizeOf; j++){
			cout << newMatrix[i][j] << "  ";
		}
	}
	cout << endl;
	cout << endl;
	return 0;
}

//Function: void mainDiag( parameterList)
//Purpose: This function divides row j by value in matrix[i][i] to get 1s in the main diagonal
void mainDiag(float initMatrix[][MAX], float newMatrix[][MAX], int sizeOf, int mainPos){
	float temp;
	int i = mainPos;

	temp = initMatrix[i][i];	//store value to divide row i by
	if(temp != 0){
		for( int j = 0; j< sizeOf; j++){	//divide row i by temp to get 1 in [i][i]
			initMatrix[i][j] = initMatrix[i][j] / temp;
			newMatrix[i][j] = newMatrix[i][j] / temp;
		}
	}else{	//throws an error when trying to divide by zero
		cout << "Cannot divide by zero - matrix is not inversible. Goodbye." << endl;
		return;
	}
}