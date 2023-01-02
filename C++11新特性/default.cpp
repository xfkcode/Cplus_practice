#include<iostream>
using namespace std;

class X
{
public:
	//让编译器提供一个默认构造函数（可类外实现）
	X() = default;
	//带参构造函数，不提供默认构造函数
	X(int i) :a(i) {}

	int a;
};
X::X() = default;
//default 只能修饰类中默认提供的构造成员函数
//无参构造、拷贝构造、赋值运算符重载、析构函数
int main()
{

	system("pause");
	return 0;
}