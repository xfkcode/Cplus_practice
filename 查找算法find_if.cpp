#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
};
void test2()
{
	vector<Person>v;
	Person p1("aaa", 15);
	Person p2("bbb", 18);
	Person p3("ccc", 16);
	Person p4("ddd", 23);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << (*it).m_Name<< (*it).m_Age << endl;
	}
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}