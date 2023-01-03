#include<iostream>
using namespace std;

//1.变长模板声明
//2.变长模板类定义
//3.边界条件

template<int...T> class Test {};

template<int first,int ... last>
class Test<first, last...>
{
public:
	static const int val = first * Test<last...>::val;
};

template<>
class Test<>
{
public:
	static const int val = 1;
};

int main()
{
	cout << Test<1, 2, 3, 4>::val << endl;
	system("pause");
	return 0;
}