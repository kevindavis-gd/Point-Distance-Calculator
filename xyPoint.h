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

