#include<iostream>
using namespace std;

void* getmalloc(int size)
{
	return malloc(size);
}
int main()
{
	//decltype 类型推导（RTTI运行时类型识别）
	//1.推演表达式类型作为变量的定义类型
	short a = 100;
	short b = 100;
	decltype(a + b) c;		//int
	cout << "c:" << typeid(c).name() << endl;

	int num = 0;
	decltype(num) x;
	const int& r = num;
	decltype(r) y = num;	//初始化
	//2.推演函数返回值类型
	cout << typeid(decltype(getmalloc)).name() << endl;		//函数名类型推导
	cout << typeid(decltype(getmalloc(0))).name() << endl;	//函数名返回值类型推导
	return 0;
}