#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//退出
	void exitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示
	void Show_Emp();
	//职工是否存在
	int IsExist(int id);
	//删除
	void Del_Emp();
	//修改
	void Mod_Emp();
	//查找
	void Find_Emp();
	//排序
	void Sort_Emp();
	//清空
	void Clean_File();
	//析构函数
	~WorkerManager();
};