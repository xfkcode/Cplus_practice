#include<iostream>
using namespace std;

class Func
{
public:
	Func(int a):_a(a) {}
	int operator()(int tmp)
	{
		return tmp + _a;
	}
private:
	int _a;
};

int main()
{
	Func obj(10);
	cout << obj(1) << endl;

	system("pause");
	return 0;
}