#include<string>
#include<iostream>
using namespace std;


void test1()
{
	string s1 = "dfebh";

	//1.[]
	for (int i = 0;i < s1.size();i++)
	{
		cout << s1[i] << " ";
		
	}
	cout << endl;
	//2.at()
	for (int i = 0;i < s1.size();i++)
	{
		cout << s1.at(i) << " ";

	}
	cout << endl;
	s1[0] = 'x';
	cout << "s1=" << s1 << endl;
	s1.at(1) = 'x';
	cout << "s1=" << s1 << endl;

}
int main()
{
	test1();
	system("pause");
	return 0;
}