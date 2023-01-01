#include<iostream>
using namespace std;

//如果一个类包含多个构造函数，C++11允许在一个构造函数中的定义使用另一个构造函数，但必须通过初始化列表进行操作
class A
{
public:
	//委托构造,只能通过列表初始化
	A() :A(1,'a') {}
	A(int x) :A(x,'b') {}
	A(char y) :A(2,y) {}
	A(int x, char y) :a(x), b(y) {}
	int a;
	char b;
};
int main()
{
	A obj1;
	cout << obj1.a << endl;
	cout << obj1.b << endl;

	A obj2(1);
	cout << obj2.a << endl;
	cout << obj2.b << endl;

	A obj3('c');
	cout << obj3.a << endl;
	cout << obj3.b << endl;

	system("pause");
	return 0;
}
