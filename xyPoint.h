/*
Name:Kevin Davis
Course:CS1063, Fall 2018, Dr.Johnson
Purpose: This program creates points with  random x and y values
and stores them in an array.
It prints those values then finds the distance between
the consecutive points and prints them out.
It then sorts the points and repeats the process.
*/

#pragma once
class xyPoint
{
public:
	xyPoint();
	xyPoint(int, int);
	~xyPoint();
private:
	int x;
	int y;
public:
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	double distance(xyPoint);
};

