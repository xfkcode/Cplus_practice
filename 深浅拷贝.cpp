#include<iostream>
using namespace std;

class Person
{
public:
	int m_age;
	int* m_height;
	Person()
	{
		cout << "默认构造" << endl;
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "有参构造" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		//m_height = p.m_height; //默认浅拷贝
		m_height = new int(*p.m_height);
		cout << "拷贝构造" << endl;
	}
	~Person()
	{
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "析构函数" << endl;
	}
};

void test()
{
	Person p1(18, 160);
	cout << "p1年龄：" << p1.m_age << "身高：" << *p1.m_height << endl;
	Person p2(p1);
	cout << "p2年龄：" << p2.m_age << "身高：" << *p2.m_height << endl;
}
//深浅拷贝
int main()
{
	test();
	return 0;
	system("pause");
}