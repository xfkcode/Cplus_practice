#include<iostream>
#include<string>
using namespace std;
//考试成绩加和
int main()
{
	string name[3] = { "张三","李四","王五" };
	int scores[3][3] = { {100,100,100},
			             {90,50,100},
						 {60,70,80} };
	for (int i = 0;i < 3;i++)
	{
		int sum = 0;
		for (int j = 0;j < 3;j++)
		{
			sum += scores[i][j];
			//cout << scores[i][j] << " ";
		}
		cout << name[i] << "的总分：" << sum << endl;
	}
	system("pause");
	return 0;
}