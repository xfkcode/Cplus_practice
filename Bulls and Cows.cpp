#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//生成随机数(伪随机)
	int num = rand() % 100 + 1;//1-100随机数
	//cout << num << endl;
	//玩家猜数
	int val = 0;
	while (1)
	{
		cin >> val;
		if (val > num)
		{
			cout << "猜测过大" << endl;
		}
		else if (val < num)
		{
			cout << "猜测过小" << endl;
		}
		else
		{
			cout << "恭喜您猜对了" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}