#include<iostream>
using namespace std;

int main()
{
	int* p = new int(10);
	int* arr = new int[10];
	for (int i = 0;i < 10;i++)
	{
		arr[i] = i;
		cout << arr[i];
	}
	cout << *p << endl;
	delete p;
	delete[] arr;
	system("pause");
	return 0;
}