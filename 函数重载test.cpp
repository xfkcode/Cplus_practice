#include<iostream>
using namespace std;

//函数重载

void func(int &a)
{
	cout << "(int& a)调用"<<endl;
}
void func(const int& a)
{
	cout << "(const int& a)调用" << endl;
}
int main()
{
	int a = 0;
	func(a);
	func(10);
	return 0;
	system("pause");
}