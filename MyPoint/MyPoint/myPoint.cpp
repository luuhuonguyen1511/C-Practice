#include <iostream>
#include <math.h>
#include "MyPoint.h"

using namespace std;

MyPoint::MyPoint()
{
	mPosX = 0;
	mPosY = 0;
}

MyPoint::MyPoint(int mPosX, int mPosY) 
{
	this->mPosX = mPosX;
	this->mPosY = mPosY;
}

MyPoint:: ~MyPoint()
{
}

void MyPoint::Display()
{
	cout << mPosX << " " << mPosY;
}

void MyPoint::SetX(int posX)
{
	this->mPosX = posX;
}

int MyPoint::GetX()
{
	return mPosX;
}

void MyPoint::SetY(int posY)
{
	this->mPosY = posY;
}

int MyPoint::GetY()
{
	return mPosY;
}

float MyPoint::Distance(MyPoint *p)
{
	return sqrt(pow(p.mPosX - mPosX, 2) + pow(p.mPosY - mPosY, 2));
}