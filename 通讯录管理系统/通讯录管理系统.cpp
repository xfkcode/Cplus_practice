#include"headerfile.h"
using namespace std;

//菜单
void showMenu()
{
	cout << "********************" << endl;
	cout << "*****  1.添加  *****" << endl;
	cout << "*****  2.显示  *****" << endl;
	cout << "*****  3.删除  *****" << endl;
	cout << "*****  4.查找  *****" << endl;
	cout << "*****  5.修改  *****" << endl;
	cout << "*****  6.清空  *****" << endl;
	cout << "*****  0.退出  *****" << endl;
	cout << "********************" << endl;
}

int main()
{
	//创建通讯录
	Addressbooks abs;
	//初始化
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1.添加
			addPerson(&abs);
			break;
		case 2://2.显示
			showPerson(&abs);
			break;
		case 3://3.删除
			deletePerson(&abs);
			break;
		case 4://4.查找
			findPerson(&abs);
			break;
		case 5://修改
			modifyPerson(&abs);
			break;
		case 6://清空
			clearPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用>_<" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}