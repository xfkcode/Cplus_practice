#include<iostream>
#include"Circle.h"
#include"Point.h"
using namespace std;


void isInCircle(Circle &c, Point &p)
{
	int dis=
		(c.getCenter().getx() - p.getx())* (c.getCenter().getx() - p.getx()) +
		(c.getCenter().gety() - p.gety()) * (c.getCenter().gety() - p.gety());
	int rdis = c.getR() * c.getR();

	if (dis == rdis)
	{
		cout << "点在圆上" << endl;
	}
	else if (dis < rdis)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

int main()
{
	Circle c;
	Point center;
	center.setx(10);
	center.sety(0);
	c.setCenter(center);
	c.setR(10);

	Point p;
	p.setx(10);
	p.sety(10);

	isInCircle(c, p);
	return 0;
	system("pause");
}