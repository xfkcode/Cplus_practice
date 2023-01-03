#include<iostream>
using namespace std;

//可变参数模板函数
template<class ... T>			//T模板参数包
void func(T ... args) {
	cout << "num =" << sizeof... (args) << endl;
}		//args函数参数包
int main()
{
	func<int>(10);
	func<int,int>(10,20);
	func<int,char>(10,'a');
	func<int, int&&, int>(10, 10, 19);
	system("pause");
	return 0;
}