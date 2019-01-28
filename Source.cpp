/*
Name:Kevin Davis
Course:CS1063, Fall 2018, Dr.Johnson
Purpose: This program creates points with  random x and y values 
and stores them in an array. 
It prints those values then finds the distance between 
the consecutive points and prints them out.
It then sorts the points and repeats the process.
*/

#include <iostream>
#include <iomanip>
#include "xyPoint.h"
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 10;

void Heading();
void CreatePointList(xyPoint arr[]);
void Printarray(xyPoint arr[]);
void Printarray(double darr[]);
void sort(xyPoint arr[]);
void getDistances(xyPoint arr[], double emptyArr[]);

int main()
{
	xyPoint pointlist[SIZE];
	double distancelist[SIZE-1];

	Heading();
	CreatePointList(pointlist);
	Printarray(pointlist);
	//find distances of consecutive points and place in distance list
	getDistances(pointlist, distancelist);
	Printarray(distancelist);
	sort(pointlist);
	Printarray(pointlist);
	getDistances(pointlist, distancelist);
	Printarray(distancelist);

	system("pause");
	return 0;
}

//******************************HEADING******************************
void Heading()
{
	cout << "Name:Kevin Davis \n"
		<< "Course:CS1063, Fall 2018, Dr.Johnson \n\n"
		<< "Purpose: This program creates points with \n"
		<< "random x and y values and stores them in an array. \n"
		<< "It prints those values then finds the distance \n"
		<< "between the consecutive points and prints them out. \n"
		<< "It then sorts the points and repeats the process.\n"
		<< "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
}

//**********************FILLING ARRAY WITH POINTS********************
void CreatePointList(xyPoint arr[])
{
	//allows the random number to be affected by time
	srand(unsigned(time(NULL)));
	for (int x = 0; x < SIZE; x++)
	{
		// Random number mod 101 gives 0 to 100 
		arr[x].setX(rand() % 101);
		arr[x].setY(rand() % 101);
	}
}

//****************************SORT ARRAY*****************************
void sort(xyPoint arr[])
{
	int place, small;
	xyPoint temppoint;
	//set swap to 1 to enter the loop
	bool swap = 1;
	// if there was a swap and x less than 10 then continue
	for (int x = 0; x < SIZE && swap; x++)
	{
		//always reset swap value
		swap = 0;
		//always reset small before rentering loop
		small = INT_MAX;
		for (int y = x; y < SIZE; y++)
		{
			//if the x value is smaller than smallest then store its position
			if (arr[y].getX() < small)
			{
				small = arr[y].getX();
				place = y;
				swap = 1;
			}
		}
		//swap the point that has smallest x value, with the x index
			temppoint = arr[place];
			arr[place] = arr[x];
			arr[x] = temppoint;
	}
}

//****************************Print xyPoint**************************
void Printarray(xyPoint arr[])
{
	cout << setw(8) << " " << "#  (  x, y )\n"
		 << setw(7)<< " " << "______________\n";
	for (int x = 0; x < SIZE; x++)
	{
		cout << setw(7) << " "<< setw(2) << x+1 <<  "  ("  
			 << setw(3) << arr[x].getX() << ","<< setw(3) 
			 << arr[x].getY() << ")\n";
	}
	cout << setw(7) << " " << "______________\n" << endl;
}

//***************************Print Distances*************************
void Printarray(double darr[])
{
	cout << setw(25) << " Distance From : \n"
		<< "----------------------------------\n";
	for (int x = 0; x < SIZE - 1; x++)
	{
		cout << "Point " << setw(2) << x + 1 << " to Point "
		     << setw(2) << x + 2 << " is: " << setw(9)
			 << fixed << setprecision(5) << darr[x]  << endl;
	}
	cout << "----------------------------------\n";
	cout << endl << endl;
}

//*************************Find Distances*****************************
void getDistances(xyPoint arr[], double emptyArr[])
{
	int x;
	double distance;
	xyPoint point1, point2;
	for (x = 0; x < SIZE-1; x++)
	{
		point1 = arr[x];
		point2 = arr[x + 1];
		distance = point1.distance(point2);
		emptyArr[x] = distance;
	}
}