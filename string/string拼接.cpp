#include<iostream>
#include<string>
using namespace std;

void test1()
{
	string s1("ÎÒ");
	s1 += "°®Äã";
	cout << "s1=" << s1 << endl;
	s1 += '!';
	cout << "s1=" << s1 << endl;
	string s2 = "Hi ";
	s2 += s1;
	cout << "s2=" << s2 << endl;
	string s3 = "I";
	s3.append(" love");
	cout << "s3=" << s3 << endl;
	s3.append(" you! ok", 5);
	cout << "s3=" << s3 << endl;
	string s4 = "abcdefgh";
	s3.append(s4,1,5);
	cout << "s3=" << s3 << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}