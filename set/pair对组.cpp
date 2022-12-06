#include<iostream>
using namespace std;

void test1()
{
	pair<string, int>p("Tom", 20);
	cout << "姓名：" << p.first << "年龄：" << p.second << endl;
	pair<string, int>P = make_pair("Jerry", 30);
	cout << "姓名：" << P.first << "年龄：" << P.second << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}