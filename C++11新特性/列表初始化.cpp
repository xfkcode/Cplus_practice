#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Foo
{
public:
	Foo(int x) :m_x(x) {}		//构造函数列表初始化
	const int m_x;				//const类型必须初始化
};
class Point
{
public:
	Point(int x, int y) :m_x(x), m_y(y) {}
private:
	int m_x;
	int m_y;
};
int main()
{
	//1.类初始化列表
	//适用性大大增加，可以用于任何类型对象的初始化
	
	//2.{}初始化
	//C++98，允许{}对数组元素初值设定
	//C++11，提供{}对标准容器初始化
	vector<int> v1 = { 1,2,3 };
	vector<int> v2{ 1,2,3 };
	map<int, int> m{ {1,2},{2,2} };
	//C++11，提供{}对动态数组初始化
	int* arr = new int[5] {1, 2, 3, 4, 5};
	//C++11，提供{}对自定义类型的列表初始化
	Point p{ 1,2 };			//Point p(1,2);
	return 0;
}