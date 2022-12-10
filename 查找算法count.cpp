#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void test1()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	int num = count(v.begin(), v.end(), 20);
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
	bool operator==(const Person &p)
	{
		if (p.m_Age == this->m_Age)
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
	Person p1("Áõ±¸", 50);
	Person p2("ÕÔÔÆ", 50);
	Person p3("Öî¸ğÁÁ", 35);
	Person p4("ÕÅ·É", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person p("¹ØÓğ", 50);
	int num = count(v.begin(), v.end(), p);
	cout << num << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}