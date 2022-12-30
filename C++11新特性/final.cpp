#include<iostream>
using namespace std;

#if 0
class A final
{
	A(){}
	void a()
	{
		cout << "hello world!";
	}
};
class B : public A {};		//B不可继承A
#endif
class C
{
public:
	C() {}
	virtual void func() final
	{
		cout << "hello world!";
	}
};
class D : public C
{
public:
	D() {}
	//void func() {} 无法重写

};
int main()
{
	//final修饰类表示该类不可被继承

	//final修饰虚函数表示该虚函数不可被子类重写
	//所有子类共用一个父类功能，不需要重写
	return 0;
}