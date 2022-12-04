#include<queue>
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test1()
{
	queue<Person> q;

	Person p1("张三", 20);
	Person p2("李四", 21);
	Person p3("王五", 30);

	q.push(p1);
	q.push(p2);
	q.push(p3);

	while (!q.empty())
	{
		cout << q.front().m_Name << q.front().m_Age << endl;
		cout << q.back().m_Name << q.back().m_Age << endl;
		q.pop();
	}
	cout << "大小：" << q.size() << endl;

}
int main()
{
	test1();
	system("pause");
	return 0;
}