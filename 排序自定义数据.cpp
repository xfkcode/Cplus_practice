#include<iostream>
#include<string>
#include<list>
using namespace std;
//年龄升序，年龄相同升高降序
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
bool comparePerson(Person&p1,Person&p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}
void test1()
{
	list<Person>L;
	Person p1("张三", 20, 175);
	Person p2("李四", 15, 160);
	Person p3("王五", 15, 180);
	Person p4("赵六", 10, 175);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);

	for (list<Person>::iterator it = L.begin();it != L.end();it++)
	{
		cout << "姓名：" << it->m_Name
			<< "年龄：" << it->m_Age
			<< "身高：" << it->m_Height << endl;
	}
	cout << "------------------------" << endl;
	cout << "排序后：" << endl;

	L.sort(comparePerson);
	for (list<Person>::iterator it = L.begin();it != L.end();it++)
	{
		cout << "姓名：" << it->m_Name
			<< "年龄：" << it->m_Age
			<< "身高：" << it->m_Height << endl;
	}
}
int main()
{
	test1();
	system("pause");
	return 0;
}