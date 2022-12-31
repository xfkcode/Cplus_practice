#include<iostream>
using namespace std;

void func1()
{
	throw 1;
}
//不能抛异常
void func2()throw() {}
//C++11新写法
void func2()noexcept {}
int main()
{
	//C++11使用noexcept替代throw()
	//代表不能抛出异常，如果抛出，就会异常
	system("pause");
	return 0;
}