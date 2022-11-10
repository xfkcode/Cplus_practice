#include<iostream>
using namespace std;

void printArr(int* p, int sz)
{
	for (int i = 0;i < sz;i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
void bubbleSort(int * p,int sz)
{
	for (int i = 0;i < sz - 1;i++)
	{
		for (int j = 0;j < sz - i - 1;j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}

	}
}
int main()
{
	int arr[] = { 1,4,6,7,9,8,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printArr(arr, sz);
	bubbleSort(arr,sz);
	printArr(arr, sz);
	system("pause");
	return 0;
}