#include<vector>
#include<deque>
#include<Algorithm>
#include<string>
#include<iostream>
#include<ctime>
using namespace std;

//5名选手，10位评委打分
//
class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		cout << "选手：" << it->m_name << "打分：" << endl;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			cout << (*dit) << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_score = avg;
	}
}
void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名：" << it->m_name << "得分：" << it->m_score << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person>v;
	createPerson(v);
	////测试
	//for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	//{
	//	cout << "姓名：" << (*it).m_name << "分数：" << (*it).m_score << endl;
	//}
	//给5名选手打分
	setScore(v);
	//显示最后得分
	showScore(v);
	system("pause");
	return 0;
}