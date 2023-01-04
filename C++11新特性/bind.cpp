#include<iostream>
#include<functional>
using namespace std;

void func(int a, int b)
{
	cout << a << " " << b << endl;
}
int main()
{
	bind(func, 1, 2)();			//func(1,2);

	//std::placeholders::_1，函数调用时，被第一个参数替换
	//std::placeholders::_2，函数调用时，被第二个参数替换
	bind(func, std::placeholders::_1, std::placeholders::_2)(11, 22);

	using namespace std::placeholders;
	bind(func, 11, _2)(22, 33, 44);			//输出11,33，_2被第二个参数替换

	system("pause");
	return 0;
}
