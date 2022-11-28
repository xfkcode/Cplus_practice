#include<iostream>
using namespace std;

//交换
template<typename T>
void mySwap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
//选择排序
//测试 char , int 数组
template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		int max = i;
		for (int j = i + 1;j < len;j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//交换max和i
			mySwap(arr[max], arr[i]);
		}
	}
}
template<typename T>
void myprint(T& Arr,int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}
void test1()
{
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	mySort(charArr, num);
	myprint(charArr, num);
}
void test2()
{
	int intArr[] = { 7,5,1,3,9,2,4,6,8 };
	int num = sizeof(intArr) / sizeof(intArr[0]);
	mySort(intArr, num);
	myprint(intArr, num);

}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}