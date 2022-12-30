#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<cstring>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		cout << "String(const char* str)" << endl;
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s) :_str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}
#if 0
	//移动构造函数（浅拷贝）
	String(String&& t)		//s(tmp) s对象在构造的时候能够使用tmp这个临时对象中的_str所指向的空间
	{
		cout << "String(String&& t)" << endl;
		_str = t._str;
		t._str = nullptr;	//不释放空间，转移另一个对象
	}
#endif
	//等价
	String(String&& t) :_str(move(t._str))
	{
		cout << "String(String&& t)" << endl;
	}
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	~String()
	{
		cout << "~String()" << endl;
		if (_str)
			delete[] _str;
	}
	friend ostream& operator<<(ostream& out, const String& t)
	{
		out << t._str;
		return out;
	}
private:
	char* _str;
};
String getString(const char* str)
{
	String tmp(str);
	return tmp;
}
int main()
{
	//左值：可以获取地址的表达式，可以出现在赋值语句的左边（const修饰不可赋值）
	//右值：无法获取地址的对象，有常量值、函数返回值、lambda表达式。
	//修改右值需要右值引用
	int a = 10;			//a是左值，10是右值
	auto b = a;			//a、b都是左值，a可用右值使用
	//左值引用
	int num = 100;
	int& num1 = num;
	//右值引用
	//语法：类型&& 引用变量名字 = 右值;
	int&& num2 = 10;
	//错误：int&& num3 = num;	左值不能右值引用
	//右值引用实际应用
	//1.移动语义
	//将临时对象的资源转移到另一个对象，整个过程开辟一段内存
	String s(getString("hello"));
	/*运行结果：
	String(const char* str)
	String(const String & s)
	~String()
	String(const String & s)
	~String()
	~String()
	*/
	
	/*添加移动构造函数运行结果： 
	String(const char* str)
	String(String&& t)
	~String()
	String(String&& t)
	~String()
	~String()
	*/

	//2.move()函数
	//将一个左值强制转化为右值引用，通过右值引用使用该值，实现移动语义
	return 0;
}