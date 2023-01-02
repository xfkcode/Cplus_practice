#include<iostream>
using namespace std;


class A
{
public:
	//基类虚函数不能用override修饰
	virtual void func(int x) {
		cout << x << endl;
	}
};
class B :public A
{
public:
	//override修饰要求重写一模一样
	void func(int x) override 
	{

	}
};
void funcAPI(A& a,int x)
{
	a.func(x);
}
int main()
{
	B b;
	funcAPI(b,3);
	system("pause");
	return 0;
}