#include<iostream>
using namespace std;

//矩形类
class rectangle
{
public:
	//长接口
	void setL(double l)
	{
		m_l = l;
		return;
	}
	double getL()
	{
		return m_l;
	}
	//宽接口
	void setW(double w)
	{
		m_w = w;
		return;
	}
	double getW()
	{
		return m_w;
	}
	bool isequal(rectangle& r)
	{
		if (m_l == r.getL() && m_w == r.getW())
			return true;
		return false;
	}
private:
	double m_l;
	double m_w;
};
int main()
{
	rectangle r1;
	double l;
	double w;
	cout << "请输入矩形1长" << endl;
	cin >> l;
	cout << "请输入矩形1宽" << endl;
	cin >> w;
	r1.setL(l);
	r1.setW(w);
	rectangle r2;
	cout << "请输入矩形2长" << endl;
	cin >> l;
	cout << "请输入矩形2宽" << endl;
	cin >> w;
	r2.setL(l);
	r2.setW(w);
	bool ret = r1.isequal(r2);
	cout << "是否相等" << ret << endl;
	return 0;
	system("pause");
}