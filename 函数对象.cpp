#include<iostream>
#include<string>
using namespace std;

class Myadd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
class Myprint
{
public:
	Myprint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;
};
void test1()
{
	Myadd myadd;
	cout << myadd(10, 10) << endl;
}
void test2()
{
	Myprint myprint;
	myprint("C++");
	myprint("C++");
	myprint("C++");
	myprint("C++");
	cout << "调用次数：" << myprint.count << endl;
}
void doprint(Myprint& mp,string test)
{
	mp(test);
}
void test3()
{
	Myprint mp;
	doprint(mp, "hello world");
}
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}
