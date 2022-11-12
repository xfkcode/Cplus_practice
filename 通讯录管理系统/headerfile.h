#pragma once
#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;//1男2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void addPerson(Addressbooks* abs);
void showPerson(Addressbooks* abs);
int isExist(Addressbooks* abs, string name);
void deletePerson(Addressbooks* abs);
void findPerson(Addressbooks* abs);
void modifyPerson(Addressbooks* abs);
void clearPerson(Addressbooks* abs);