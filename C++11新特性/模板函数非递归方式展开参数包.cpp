#include<iostream>
using namespace std;

template<typename T>
void print(T tmp)
{
	cout << tmp << endl;
}
//可变参数模板函数
template<typename ... T>
void expand(T ... args)
{
	//逗号运算符
	//初始化列表
	int a[] = { (print(args),0) ... };
}
int main()
{
	expand(1,2,3,4);
	system("pause");
	return 0;
}