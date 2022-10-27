#include<iostream>
using namespace std;
//ÔªËØÄæÖÃ
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	while (left<right)
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
	system("pause");
}