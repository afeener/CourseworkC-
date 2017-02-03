// File: wavefront.cpp
// Author: Alex Feener
// CSCI 4360 wavefront
// Purpose: program a mobile robot to do motion planning with
//		the wavefront planning algorithm. The objective is to
//		navigate a known obstacle course (a "world") from a 
//		given starting point to a given goal point, while
//		not coming in contact with any obstacles nor running
//		outside the "world" space.

#include <iostream>
#include <string>

using namespace std;

// functions
void WavefrontSearch(int array[8][16]);

const int ROW = 8;
const int COL = 16;

int main(){
	//world1
	int worldArray[8][16] ={{2,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1},
							{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
							{0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}};
	
	//world2
	//int worldArray[8][16] ={{2,0,0,0,0,0,0,1,1,1,1,0,0,1,0,0},
	//						{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
	//						{0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,0},
	//						{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0},
	//						{0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0},
	//						{0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
	//						{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	//						{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}};

	//int pathArray[];
	//
	

	//for(int i = 0; i < 8; i++){
	//	for( int j = 0; j < 16; j++)

	//ask user for goal location.
	WavefrontSearch(worldArray);
	cout << "The altered array is: " << endl;
		for( int i = 0; i < ROW; i++){
			cout << endl;
			for(int j = 0; j < COL; j++){
				cout << worldArray[i][j] << "  ";
		}
	}


//To plan an optimal path, you start at the goal, and at every point, until 
		//you've reached the goal, you pick the next cell that has the minimum 
		//value of all adjacent cells. For example, one good path from S to G 
		//(with each cell represented by its x,y Cartesian coordinates, starting 
		//at 0,0 in the lower-left corner):

	cout << endl;
	cout << endl;
	int x = 5;
	int y = 7;
	int currentVal = worldArray[x][y];
	 while(currentVal != 2 )
		 {
			 // //setting currentVal to the goal spot
			 

			  //if [goalx -1][ y] != 1 && < current val && if the row is not 0 (to keep in bounds)
			  // move up, change prev to 99, increment pathcount
			  if( (worldArray[x - 1][y] < currentVal) && worldArray[x -1][y] != 1  && x != 0)
			  {
				  currentVal = worldArray[x - 1][y];
				  x = (x - 1);
				  worldArray[x][y] = 98;

			  }
			  //if [goalx][goaly-1] != 1 && < curr val
			  // move left, change prev val to 99, increment pathcount
			  else if ( (worldArray[x][y - 1] < currentVal) && worldArray[x][y - 1] != 1  && y != 0)
			  {
				  currentVal = worldArray[x][y - 1];
				  y = (y - 1);
				  worldArray[x][y] = 98;
			  }
			    //if goalx+1 goaly != 1 && < curr val
			  // move down, chg prev 99, inc pathcount
			
			  else if ( (worldArray[x + 1][y] < currentVal) && worldArray[x + 1][y] != 1  && y != 0)
			  {
				  currentVal = worldArray[x + 1][y];
				  x = (x + 1);
				  worldArray[x][y] = 98;
			  } 
			  //if goalx goaly+1 != 1 && < curr val
			  // move right, chg prev 99, inc pathcount
			  else if ( (worldArray[x][y + 1] < currentVal) && worldArray[x][y + 1] != 1  && y != 0)
			  {
				  currentVal = worldArray[x][y + 1];
				  y = (y + 1);
				  worldArray[x][y] = 98;
			  }
	 }

	 	cout << "The Path array is: " << endl;
		for( int i = 0; i < ROW; i++){
			cout << endl;
			for(int j = 0; j < COL; j++){
				cout << worldArray[i][j] << "  ";
		}
	}
		cout << endl;
	//print out the # of steps from (x_start, y_start) to (x_goal, y_goal)

	//print the path using coordinates

	return 0;
}

void WavefrontSearch( int array[8][16])
{
  int goal_x, goal_y, goal;
  bool foundWave = true;
  int currentWave = 2; //Looking for goal first
  
  cout << "Please enter x coordinate of goal:" << endl;
  cin >> goal_x;
  cout << "Please enter y coordinate of goal:" << endl;
  cin >> goal_y;
  cout << endl;

  array[goal_x][goal_y] = 98; //set goal
  goal = 98;

  while(foundWave == true)
  {
    foundWave = false;
    for(int y=0; y < COL; y++)
    {
      for(int x=0; x < ROW; x++)
      {
        if(array[x][y] == currentWave)
        {
          foundWave = true;
          goal_x = x;
          goal_y = y;
		  
		
		  //to output path: on temp array, if array[i][j] != 1 && != 0, 
		  //cout << "(" << i << ", " << j << ")"
		  //print number of steps
		  //	cout << "The number of steps from (0, 0) to (" << x_goal << ", << y_goal << ") is" << pathcount << endl;
          if(goal_x > 0) //This code checks the array bounds heading WEST
            if(array[goal_x-1][goal_y] == 0)  //This code checks the WEST direction
              array[goal_x-1][goal_y] = currentWave + 1;
 
          if(goal_x < (ROW - 1)) //This code checks the array bounds heading EAST
            if(array[goal_x+1][goal_y] == 0)//This code checks the EAST direction
              array[goal_x+1][goal_y] = currentWave + 1;
 
          if(goal_y > 0)//This code checks the array bounds heading SOUTH
            if(array[goal_x][goal_y-1] == 0) //This code checks the SOUTH direction
              array[goal_x][goal_y-1] = currentWave + 1;
 
          if(goal_y < (COL - 1))//This code checks the array bounds heading NORTH
            if(array[goal_x][goal_y+1] == 0) //This code checks the NORTH direction
              array[goal_x][goal_y+1] = currentWave + 1;
        }
      }
    }
    currentWave++;
  }


}