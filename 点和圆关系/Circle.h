#pragma once
#include<iostream>
#include"Point.h"
using namespace std;

//Բ
class Circle
{
	int m_R;
	Point m_center;
public:
	void setR(int r);

	int getR();

	void setCenter(Point center);

	Point getCenter();
};