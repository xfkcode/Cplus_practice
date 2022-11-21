#include<iostream>
#include<string>
using namespace std;

//友元
class Building;
class GoodGay
{
public:
	GoodGay();
	void visit();
	Building * building;
};
class Building
{
	friend void goodGay(Building* building);//全局函数友元
	friend class GoodGay;//类友元
	friend void GoodGay::visit();//类成员函数友元
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	this->building = new Building;
}
void GoodGay::visit()
{
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}

void goodGay(Building *building)
{
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}

void test1()
{
	Building building;
	goodGay(&building);
}
void test2()
{
	GoodGay gg;
	gg.visit();
}
int main()
{
	test1();
	test2();
	return 0;
	system("pause");
}