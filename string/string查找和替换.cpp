#include<string>
#include<iostream>
using namespace std;

void ret(int pos)
{
	if (pos == -1)
	{
		cout << "Î´ÕÒµ½" << endl;
	}
	else
	{
		cout << "pos=" << pos << endl;
	}
	return;
}
void test1()
{
	string s1 = "abcdefghi";
	int pos1 = s1.find("de");
	ret(pos1);
	
	string s2 = "abcdefdefgh";
	int pos2 = s2.rfind("def");
	ret(pos2);
}
void test2()
{
	string s1 = "abcdef";
	s1.replace(1, 3, "1111");
	cout << "s1=" << s1 << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}