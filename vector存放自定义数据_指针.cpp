#include<iostream>
#include<string>
#include<vector>
#include<Algorithm>
using namespace std;

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
void test1()
{
	vector<Person> v;

	Person p1("aaa", 1);
	Person p2("bbb", 2);
	Person p3("ccc", 3);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	cout << "自定义数据class：" << endl;
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it).m_Name << "\t" << (*it).m_Age << endl;
		cout << it->m_Name << "\t" << it->m_Age << endl;
	}
}
void test2()
{
	vector<Person*> v;

	Person p1("aaa", 1);
	Person p2("bbb", 2);
	Person p3("ccc", 3);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	cout << "指针：" << endl;
	for (vector<Person*>::iterator it = v.begin();it != v.end();it++)
	{
		cout << (*it)->m_Name << "\t" << (*it)->m_Age << endl;
	}
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}