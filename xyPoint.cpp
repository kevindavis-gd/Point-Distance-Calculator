/*
Name:Kevin Davis
Course:CS1063, Fall 2018, Dr.Johnson
Purpose: This program creates points with  random x and y values
and stores them in an array.
It prints those values then finds the distance between
the consecutive points and prints them out.
It then sorts the points and repeats the process.
*/

#include "xyPoint.h"
#include <cmath>


xyPoint::xyPoint()
{
	x = 0;
	y = 0;
}
xyPoint::xyPoint(int firstnum, int secondnum)
{
	x = firstnum;
	y = secondnum;
}
xyPoint::~xyPoint()
{
}

// ******************SETTERS*************************
void xyPoint::setX(int num1)
{
	x = num1;
}

void xyPoint::setY(int num2)
{
	y = num2;
}

// ******************GETTERS*************************
int xyPoint::getX()
{
	return x;
}

int xyPoint::getY()
{
	return y;
}

//*******************Distance Calculation*************
double xyPoint::distance(xyPoint p2)
{
	double dist, numx, numy, power;
	//separate variables of the point p2 into integers
	numx = (p2.x - x);
	numy = (p2.y - y);
	power = 2;
	//calculate the distance with the formula
	dist = sqrt( (pow(numx, power)) + (pow(numy, power)) );
	return dist;
}
