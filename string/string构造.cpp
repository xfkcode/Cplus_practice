#include<string>
#include<iostream>
using namespace std;

void test1()
{
	//string();
	string s1;
	//string(const char* str);
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	//string(const string& str);
	string s3(s2);
	cout << "s3=" << s3 << endl;
	//string(int n,char c);
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}