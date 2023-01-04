#include<iostream>
using namespace std;

int main()
{
	int a = 10;				//a左值
	int&& b = std::move(a);	//将左值转换位右值	
	cout << "c = " << endl;
	system("pause");
	return 0;
}