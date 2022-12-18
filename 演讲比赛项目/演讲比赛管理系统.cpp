#include"speechManager.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;

	////测试12名选手创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	//{
	//	cout << "选手编号：" << it->first 
	//		 << "姓名：" << it->second.m_Name 
	//		 << "分数：" << it->second.m_Score[0]
	//		 << endl;
	//}

	int choice = 0;
	while (true)
	{
		sm.ShowMenu();

		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.starSpeech();
			break;
		case 2://查看往届比赛记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	system("pause");
	return 0;
}