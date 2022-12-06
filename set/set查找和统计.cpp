#include<set>
#include<iostream>
using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	printSet(s1);

	set<int>::iterator pos = s1.find(20);
	if (pos != s1.end())
	{
		cout << "找到元素：" << *pos << endl;
	}
	else 
	{
		cout << "未找到元素" << endl;
	}
}
void test2()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	int num = s1.count(20);
	cout << "num=" << num << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}