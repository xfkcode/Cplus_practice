#include<iostream>
#include<string>
using namespace std;

//学生类
class Student 
{
public:
	string m_name;
	string m_number;
	void Init()
	{
		cout << "请输入姓名：" << endl;
		cin >> m_name;
		cout << "请输入学号：" << endl;
		cin >> m_number;
	}
	void show()
	{
		cout << "姓名：" << m_name << endl;
		cout << "学号：" << m_number << endl;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setID(string id)
	{
		m_number = id;
	}
};

int main()
{
	Student s1;
	//s1.Init();
	string name;
	string ID;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入学号：" << endl;
	cin >> ID;
	s1.setName(name);
	s1.setID(ID);
	s1.show();
	return 0;
	system("pause");
}