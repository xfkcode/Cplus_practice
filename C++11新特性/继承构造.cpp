#include<iostream>
using namespace std;

class A
{
public:
	A(int x, int y)
	{
		this->a = x;
		this->b = y;
	}
protected:
	int a;
	int b;
};
class B :public A
{
public:
#if 0
	//通过参数列表给基类构造函数传参
	B(int x, int y)
		:A(x, y)
	{

	}
#endif
	//继承构造（等价）
	using A::A;
	void display()
	{
		cout << "a =" << a << ",b = " << b << endl;
	}
	//没有增加新的成员变量
};

int main()
{
	//C++11允许派生类继承基类的构造函数（默认构造、拷贝构造、移动构造除外）
	B obj(10, 20);
	obj.display();
	system("pause");
	return 0;
}