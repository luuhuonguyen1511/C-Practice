#pragma once
#ifndef myPoint_h
#define myPoint_h

class MyPoint
{
public:
	MyPoint();
	MyPoint(int, int);
	virtual ~MyPoint();
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPoint*);

private:
	int mPosX;
	int mPosY;
};
#endif