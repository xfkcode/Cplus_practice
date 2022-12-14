#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Mystring
{
public:
	//构造函数
	Mystring(char* tmp)
	{
		cout << "构造函数" << endl;
		this->_len = strlen(tmp);
		this->_str = new char[_len + 1];
		strcpy(_str, tmp);
	}
	//拷贝构造
	Mystring(const Mystring& s)
	{
		cout << "拷贝函数" << endl;
		_len = s._len;
		_str = new char[_len + 1];
		strcpy(_str, s._str);
	}
	//移动构造函数
	Mystring(Mystring&& t)
	{
		cout << "移动构造函数" << endl;
		_str = t._str;		//拷贝地址，没有重新申请内存
		_len = t._len;
		t._str = nullptr;	//原来指针置空
	}
	//赋值运算符重载
	Mystring& operator=(const Mystring& s)
	{
		cout << "赋值运算符重载" << endl;
		if (&s == this)
		{
			return *this;
		}
		if (_str != NULL)
		{
			delete[] _str;
			_str = nullptr;
		}
		_len = s._len;
		_str = new char[_len + 1];
		strcpy(_str, s._str);
		return *this;
	}
	//析构函数
	~Mystring()
	{
		cout << "析构函数" << endl;
		if (_str != NULL)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
	int _len;
};

Mystring  func()
{
	char s[] = "abcd";
	Mystring obj(s);
	return obj;
}

int main()
{
	Mystring&& tmp = func();
	system("pause");
	return 0;
}
