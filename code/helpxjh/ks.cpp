#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>

#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<vector>
#include<fstream>
#include<list>
#include <iomanip>
using namespace std;

class Person {

public:
	bool m_D = false;
	bool m_E = false;
	bool m_F = false;

	Person(string a, string b, string  c) :m_A(a), m_B(b), m_C(c) {}
	void PrintPerson() {

		cout << "现在共有三位玩家：" << m_A << "和" << m_B << "和" << m_C << endl;
	}
private:
	string m_A;
	string  m_B;
	string  m_C;
};


int main() {
	cout << "开始抢地主啦！" << endl;
	srand((unsigned)time(NULL));
 	int q[3];
	for (int i=0; i <= 2; i++)
	{
		q[i] = rand() % 4;
		for (int j = 0; j < i; j++)
		{
			while (q[j] == q[i])
			{
				q[i] = rand() % 4;
				continue;
			}
		}
	}
	for (int n = 0; n < 3; n++) {
		cout << q[n] << endl;
	}
Person p("张三", "李四", "王五");
p.PrintPerson();
	int maxs = max(q[0],max(q[1],q[2]));

	if (q[0] == maxs) { cout << "地主是张三" << endl; p.m_D = true; }

	else if (q[1] == maxs) { cout << "地主是李四" << endl;  p.m_E = true; }

	else { cout << "地主是王五" << endl;  p.m_F = true; }



	system("pause");
	return 0;
	}
