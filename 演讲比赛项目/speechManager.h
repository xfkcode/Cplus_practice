#pragma once
#include"speaker.h"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

class SpeechManager
{
public:
	//构造函数
	SpeechManager();
	//菜单
	void ShowMenu();
	//退出系统
	void exitSystem();
	//析构函数
	~SpeechManager();
	//初始化成员
	void initSpeech();
	//创建12名选手
	void createSpeaker();
	
	//开始比赛
	void starSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示得分
	void showScore();
	//保存记录
	void saveRecord();
	//查看记录
	void loadRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
	//显示往届得分
	void showRecord();
	//清空记录
	void clearRecord();

	//成员属性
	//第一轮比赛先手编号
	vector<int>v1;
	//第二轮比赛选手编号
	vector<int>v2;
	//胜出前三名选手编号
	vector<int>vVictory;
	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;
	//比赛轮数
	int m_Index;
};