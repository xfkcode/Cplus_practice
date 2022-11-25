#include<iostream>
#include<string>
using namespace std;

//多态制作饮品
class AbstractDrinking
{
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
//制作咖啡
class Coffee :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "煮水（农夫山泉）" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};
//制作茶
class Tee :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "煮水（农夫山泉）" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};

//制作函数
void dowork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}
void test()
{
	dowork(new Coffee);
	cout << "-----------" << endl;
	dowork(new Tee);
}
int main()
{
	test();
	return 0;
	system("pause");
}