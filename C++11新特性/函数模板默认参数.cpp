#include<iostream>
using namespace std;

//普通函数默认参数
void func1(int a = 3) {}
//类模板默认模板参数，多参数从右向左
template<class T1,class T2=int>
class A {};
//函数模板默认模板参数C++11，多参数可以从左向右,也可从右向左
template<typename T1=int,typename T2>
void func2(T1 a,T2 b) {}

int main()
{

	system("pause");
	return 0;
}