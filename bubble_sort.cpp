#include<iostream>
using namespace std;
//ц╟ещеепР
int main()
{
	int arr[] = { 4,57,2,45,86,55,467 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}	
	}
	for (int k = 0;k < len;k++)
	{
		cout << arr[k] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}