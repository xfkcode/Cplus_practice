#include<iostream>
#include<memory>			//智能指针
using namespace std;

int main()
{
	shared_ptr<int> sp1(new int(11));				//创建智能指针对象
	shared_ptr<int> sp2 = sp1;						//拷贝构造，有两个对象与堆区空间绑定
	
	weak_ptr<int> wp1 = sp1;						//不和堆区绑定

	cout << "num =" << sp1.use_count() << endl;
	cout << "num =" << wp1.use_count() << endl;

	shared_ptr<int> sp3 = wp1.lock();				//lock函数获取shared_ptr<int>对象

	cout << "num =" << sp1.use_count() << endl;
	cout << "num =" << wp1.use_count() << endl;

	cout << *sp1 << " " << *sp2 << " " << *sp3 << endl;
	//cout << *wp1 << endl;							//err

	sp1 = nullptr;
	sp2 = nullptr;
	sp3 = nullptr;
	cout << "num =" << sp1.use_count() << endl;
	cout << "num =" << wp1.use_count() << endl;

	shared_ptr<int> tmp = wp1.lock();				//堆区已释放，获取nullptr
	if (tmp == nullptr)
	{
		cout << "堆区空间已经释放" << endl;
	}

	system("pause");
	return 0;
}
