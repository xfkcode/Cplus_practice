#include<string>
#include<iostream>
using namespace std;

void test1()
{
	string s1 = "hello";
	cout << "s1=" << s1 << endl;
	s1.insert(1, "111");
	cout << "s1=" << s1 << endl;
	s1.erase(1, 3);
	cout << "s1=" << s1 << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}