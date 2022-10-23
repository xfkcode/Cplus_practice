#include<iostream>
using namespace std;

int main()
{
	//gotoÓï¾ä
	cout << 1 << endl;
	cout << 2 << endl;
	goto FLAG;
	cout << 3 << endl;
	cout << 4 << endl;
	FLAG:
	cout << 5 << endl;
	return 0;
	system("pause");
}