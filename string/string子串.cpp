#include<string>
#include<iostream>
using namespace std;

void test1()
{
	string s1 = "hello";
	cout << "s1=" << s1 << endl;
	string s2;
	s2 = s1.substr(0, 3);
	cout << "s2=" << s2 << endl;
}
void test2()
{
	string email = "zhangsan@163.com";
	int pos = email.find('@');
	string name = email.substr(0, pos);
	cout << name << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}