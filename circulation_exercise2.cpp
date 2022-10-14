#include<iostream>
using namespace std;
//敲桌子，7的倍数：%7=0，个位有7：%10=7，十位有7：/10=7
int main()
{
	for (int i = 1;i <= 100;i++)
	{
		if (i % 7 == 7 || i % 10 == 7 || i / 10 == 7)      
		{
			cout << "敲桌子" << endl;
		}
	cout << i << endl;
	}

	system("pause");
	return 0;
}