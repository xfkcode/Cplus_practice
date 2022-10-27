#include<iostream>
using namespace std;
//找出数组中最大值
int main()
{
	int arr[] = { 64,7,84,5,9,564,945 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int max = 0;
	for (int i = 0;i < len;i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << "最大值为:" << max << endl;
	return 0;
	system("pause");
}