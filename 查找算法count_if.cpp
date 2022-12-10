#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Greater15
{
public:
	bool operator()(int val)
	{
		return val > 15;
	}
};
void test1()
{
	vector<int>v;
	v.push_back(15);
	v.push_back(15);
	v.push_back(26);
	v.push_back(10);
	v.push_back(15);
	int num = count_if(v.begin(), v.end(), Greater15());
	cout << num << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
class AgeGreater
{
public:
	bool operator()(const Person& p)
	{
		return p.m_Age > 20;
	}
};
void test2()
{
	vector<Person>v;
	Person p1("Áõ±¸", 35);
	Person p2("ÕÅ·É", 35);
	Person p3("ÕÔÔÆ", 30);
	Person p4("¹ØÓğ", 35);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	int num = count_if(v.begin(), v.end(), AgeGreater());
	cout << num << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}