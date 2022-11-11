#include<iostream>
#include<string>
using namespace std;

//结构体按成员排序
struct hero
{
	string name;
	int age;
	string sex;
};
void Sort(struct hero hArr[], int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (hArr[j].age > hArr[j + 1].age)
			{
				struct hero temp = hArr[j];
				hArr[j] = hArr[j + 1];
				hArr[j + 1] = temp;
			}
		}
	}
}
void PrintHero(struct hero hArr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << "英雄姓名：" << hArr[i].name << "年龄：" << hArr[i].age
			<< "性别：" << hArr[i].sex << endl;
	}
}
int main()
{
	struct hero hArr[5] =
	{
		{"刘备",23,"男"},
		{"关羽",24,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",18,"女"}
	};
	Sort(hArr, 5);
	PrintHero(hArr, 5);
	return 0;
	system("pause");
}