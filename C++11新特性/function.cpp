#include<iostream>
#include<functional>
using namespace std;

//1.普通函数
void func()
{
	cout << __func__ << endl;
}
//2.类中静态函数
class Test
{
public:
	static int test_func(int a)
	{
		cout << __func__ << "(" << a << ") ->:";
		return a;
	}
};
//2.类中仿函数
class Func
{
public:
	int operator()(int a)
	{
		cout << __func__ << "(" << a << ") ->:";
		return a;
	}
};
int main()
{
	function<void(void)> f1 = func;
	f1();

	function<int(int)> f2 = Test::test_func;
	cout << f2(10) << endl;

	Func obj;
	function<int(int)> f3 = obj;
	cout << f3(22) << endl;

	//用处：实现函数回调
	//类似于函数指针，不能比较相等或不相等，但可以与NULL、nullptr比较
	system("pause");
	return 0;
}