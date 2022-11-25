#include<iostream>
#include<string>
using namespace std;

//多态计算器
class Abstract
{
public:
	//父类虚函数
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class Add:public Abstract
{
public:
	//子类重写
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
class Sub :public Abstract
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};

void test()
{
	//父类指针指向子类对象
	Abstract* abc = new Add;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << "加：" << abc->getResult() << endl;
	delete abc;

	abc = new Sub;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << "减：" << abc->getResult() << endl;
	delete abc;
}
int main()
{
	test();
	return 0;
	system("paude");
}