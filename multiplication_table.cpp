#include<iostream>
using namespace std;

int main()
{
	//³Ë·¨¿Ú¾÷±í
	for (int i = 1;i <= 9;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}
	return 0;
	system("pause");
}