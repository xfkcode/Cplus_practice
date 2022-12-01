#include<string>
#include<iostream>
using namespace std;

void result(int ret)
{
	if (ret == 0)
	{
		cout << "s1=s2" << endl;
	}
	else if (ret == 1)
	{
		cout << "s1>s2" << endl;
	}
	else
	{
		cout << "s1<s2" << endl;

	}
}
void test1()
{
	string s1 = "dfebh";
	string s2 = "dfsicociwdc";
	int ret = s1.compare(s2);
	result(ret);
}
int main()
{
	test1();
	system("pause");
	return 0;
}