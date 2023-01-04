#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

int tmp{1};

class A
{
public:
	void func()
	{
		//[]类成员变量，全局变量，不可以局部变量
		auto f1 = [=]() {cout<<_a<<endl;};
		auto f2 = [&]() {cout << _a << endl;};
		auto f3 = [this]() {
			cout << _a << endl;
			cout << tmp << endl;
		};
	}

	int _a=1;

};
//回调函数
int func(function<int(int,int)>f1, int x, int y)
{
	return f1(x, y);
}
int main()
{
	int a = 0;
	int b = 0;
	auto f1 = []() {};
	//a,b值传递
	auto f2 = [a, b]() {cout << a << " " << b << endl;};
	f2();
	auto f3 = [a, b](int x,int y) {
		cout << a << " " << b << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	};
	f3(1, 2);
	//值传递
	auto f4 = [=] {cout << a << " " << b << endl;};
	//引用传递
	auto f5 = [&] {cout << a << " " << b << endl;};
	//a值传递，其他引用传递
	auto f6 = [& ,a] {cout << a << " " << b << endl;};
	//a引用传递，其他值传递
	auto f7 = [= ,&a] {cout << a << " " << b << endl;};

	//默认const不可修改，若要改加mutable
	auto f8 = [=]() mutable
		{
			a++;
			cout <<"a =" << a << endl;
			cout << "tmp =" << tmp << endl;
		};
	f8();

	function<int(int)> f9 = [](int a) {return a + 1;};
	cout << f9(1) << endl;

	function<int(int)> f10 = bind(
		[](int a) {return a + 1;},
		_1
	);
	cout << f10(2) << endl;

	//函数指针
	typedef int(*FUNCptr)(int, int);
	FUNCptr fp = [](int a, int b) {return a + b;};
	cout << fp(1,2) << endl;

	//回调函数
	auto ret = func([](int x, int y) {return x + y;}, 1, 2);
	cout << ret << endl;

	system("pause");
	return 0;
}