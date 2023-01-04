#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

class Test
{
public:
	static void func1(int a, int b)
	{
		cout << a << " " << b << endl;
	}
	void func2(int a, int b)
	{
		cout << a << " " << b << endl;
	}
	int _a;

};
int main()
{
	function<void(int, int)> f1 = Test::func1;
	
	//function<void(int, int)> f2 = Test::func2;	//err
	Test obj;
	function<void(int, int)> f2 = bind(&Test::func2, &obj, _1, _2);
	f2(11, 22);		//obj.func(11,22);

	function<int &()> f3 = bind(&Test::_a, &obj);
	f3() = 111;		//obj._a = 111;
	cout << obj._a << endl;
	system("pause");
	return 0;
}