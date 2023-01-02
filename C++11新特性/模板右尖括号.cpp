#include<iostream>
using namespace std;

template<class T> class X {};
template<class T> class Y {};

int main()
{
	//C++11前，两个右尖括号之间必须有空格
	Y<X<int> > obj;			
	Y<X<int>> obj;
	system("pause");
	return 0;
}