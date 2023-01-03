#include<iostream>
using namespace std;

//1.可变参数模板声明
//2.递归继承模板类
//3.边界条件

template<class ... T> class Car {};

template<class Head,class ... Tail>
class Car<Head, Tail ...>:public Car<Tail...>
{
public:
	Car()
	{
		cout << "type = " << typeid(Head).name() << endl;
	}
};

template<> class Car<> {};

int main()
{
	Car<int, char*> bmw;
	system("pause");
	return 0;
}