#include<iostream>
using namespace std;
//获取三位数的水仙花数
int main()
{
	int num = 0;
	do
	{
		int a = 0;
		int b = 0;
		int c = 0;

		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;

		if (a*a*a+b*b*b+c*c*c==num)
		{
			cout << num << endl;
		}
		num++;
	} while (num < 1000);
	system("pause");
	return 0;
}