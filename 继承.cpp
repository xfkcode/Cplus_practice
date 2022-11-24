#include<iostream>
using namespace std;

class A
{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class B : public A{};
//public:int a;
//protected:int b;
//int c;不能访问
class C : protected A{};
//protected:int a;int b;
//int c;不能访问
class D : private A{};
//private:int a;int b;
//int c;不能访问
int main()
{
	return 0;
	system("pause");
}