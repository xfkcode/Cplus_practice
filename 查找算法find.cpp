#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
	vector<int>v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
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
	bool operator== (const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};
void test2()
{
	vector<Person>v;
	Person p1("a", 1);
	Person p2("b", 2);
	Person p3("c", 3);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	Person pp("a", 1);
	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << (*it).m_Age<< (*it).m_Name << endl;
	}
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}