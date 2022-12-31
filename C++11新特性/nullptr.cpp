#include<iostream>
using namespace std;

void func(int a)
{
	cout << "int a" << endl;
}
void func(int* a)
{
	cout << "int* a" << endl;
}
int main()
{
	int* p1 = NULL;
	int* p2 = 0;

	func(NULL);
	func(nullptr);
	//nullptr只能给指针赋值
	system("pause");
	return 0;
}
