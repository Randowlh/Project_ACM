#include<iostream>
#include<string>
#include<cstdlib>
#include <ctime>
#include<algorithm>
#include <time.h>
#include<stdlib.h>
using namespace std;





int panchong(int m, int x[54]);
int pdycl(int a);
void paichuli(int* x,int m);
void paixvchuli(int* x,int m);
void paishu(int* x, int m);







void paichuli(int* x,int m)
{
	for (int i = 0; i < m; i++)
	{
		if (*(x+i) % 13 == 0)
		{
			*(x+i) = 13;
		}
		if ((*(x + i) <= 52) && (*(x + i) % 13 != 0))
		{
			*(x + i) = *(x + i) % 13;
		}
		if (*(x + i) == 53)
		{
			*(x + i) = 14;

		}
		if (*(x + i) == 54)
		{
			*(x + i) = 15;

		}
	}
}
void paixvchuli(int* x,int m)
{
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < m-1 - i; j++)
		{

			if (pdycl(x[j]) < pdycl(x[j+1]))
			{
				int temp = *(x + j);
				*(x + j) = *(x + j + 1);
				*(x + j + 1) = temp;
			}

		}

	}
}

void paishu(int* x,int m)
{
	for (int i = 1; i < 16; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(x + j) == i)
			{
				*(x + i-1) += 1;
			}
		}
	}
}

int pdycl(int a)
{
	if (a > 13)

	{
		a = a + 3;
	}
	if (a < 3)
	{
		a = a + 13;

	}
	return  a;
}
int panchong(int m, int x[54])
{
	for (int i = 0; i < 54; i++)
	{
		if (m == x[i])
		{
			return 0;
		}
	}
	return 1;
}







int main()
{



	//开始程序



	cout << "                               **********************************************************" << endl;
	cout << "                               *                                                        *" << endl;
	cout << "                               *                  欢迎来到斗地小组系统V1.0              *" << endl;
	cout << "                               *                                                        *" << endl;
	cout << "                               **********************************************************" << endl;
	string user_name,computer1, computer2; int bot1,bot2;

	do { cout << "请输入您的姓名" << endl; cin >> user_name;} while (user_name.empty());

	cout << "请选择您的对手  1谢哲  2徐天乐  3张智超" << endl;
	cin >> bot1;
	cout << "*********"<<endl;
	cin >> bot2;
	switch (bot1)
	{
	case 1: {computer1 = "谢哲"; break; }
	case 2: {computer1 = "徐天乐"; break; }
	case 3: {computer1 = "张智超"; break; }
	}
	switch (bot2)
	{
	case 1: {computer2 = "谢哲"; break; }
	case 2: {computer2 = "徐天乐"; break; }
	case 3: {computer2 = "张智超"; break; }
	}











	//发牌程序
	int paiku[54] = {};
	int paiku_n1[17] = {};
	int jipai_n1[15] = {};
	int paiku_n2[17] = {};
	int jipai_n2[15] = {};
	int paiku_d[20] = {};
	int jipai_d[15] = {};
	int pailei_n1[12] = {};
	int pailei_n2[12] = {};
	int pailei_d[12] = {};
	int even[54];
	int dipai[3];


	for (int i = 0; i < 54;i++)
	{
		paiku[i] = i + 1;
	}
	int leftNum = 54;
	int ranNumber;

	//发牌
	for (int i = 0; i < 17; i++)
	{
		srand((unsigned)time(NULL));

		ranNumber = rand() % leftNum;
		paiku_n1[i] = paiku[ranNumber];
		paiku[ranNumber] = paiku[leftNum - 1];

		leftNum--;
	}
	for (int i = 0; i < 17; i++)
	{
		srand((unsigned)time(NULL));

		ranNumber = rand() % leftNum;
		paiku_n2[i] = paiku[ranNumber];
		paiku[ranNumber] = paiku[leftNum - 1];

		leftNum--;
	}
	for (int i = 0; i < 17; i++)
	{
		srand((unsigned)time(NULL));

		ranNumber = rand() % leftNum;
		paiku_d[i] = paiku[ranNumber];
		paiku[ranNumber] = paiku[leftNum - 1];

		leftNum--;
	}

	for (int i = 0; i < 3; i++) {

		paiku_d[17 + i] = paiku[i];
		dipai[i] = paiku[i];

	}


	cout << "三家的牌已经发好" << endl;
	cout << "*************************" << endl;
	//叫地主程序

	class Person {
	public:
		bool m_D = false;//定义人类的属性，方便规定出牌顺序
		bool m_E = false;
		bool m_F = false;
		Person(string a, string b, string  c) :m_A(a), m_B(b), m_C(c) {}//初始化列表方法传入人名
		void PrintPerson() {
			cout << "现在共有三位玩家：" << m_A << "和" << m_B << "和" << m_C << endl;//输出人名
		}
	private:
		string m_A;
		string  m_B;
		string  m_C;
	};


	cout << "开始抢地主啦！" << endl;//开始抢地主
	cout << "**************************" << endl;
	srand((unsigned int)time(NULL));//生成三个不同的随机数
	int q[3]; int score;
	for (int i = 0; i <= 1; i++) {
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
	cout << computer1 << "叫了" << q[0] << "分" << endl;
	cout << computer2 << "叫了" << q[1] << "分" << endl;
	cout << "请选择您叫分的分数    0分   1分  2分  3分" << endl;
	cin >> score;
	cout << "**************************" << endl;
	q[2] = score;
	for (int n = 0; n < 3; n++) {
		cout << q[n] << endl;//输出三个不同的随机数
	}

	Person p(computer1, computer2, user_name);//传入人名
	p.PrintPerson();
	int maxs = max(q[0], max(q[1], q[2]));//定义最大值函数
	if (q[0] == maxs) { cout << "地主是" << computer1 << endl; p.m_D = true; }//地主的确定
	else if (q[1] == maxs) { cout << "地主是" << computer2 << endl;  p.m_E = true; }
	else { cout << "地主是" << user_name << endl;  p.m_F = true; }


	paichuli(dipai,3);
		cout << "底牌为：";
		for (int i = 0; i < 3; i++)
		{
			cout << '[' << dipai[i] << ']';
		}
		cout << endl;
	//理用户的牌

	if (p.m_F)
	{
		paichuli(paiku_d,20);
		paixvchuli(paiku_d,20);
		paishu(jipai_d,15);
		cout << "**************************" << endl;
		cout << "您的牌为：" << "   ";
		for (int i = 0; i < 20;i++)
		{
			cout << '[' << paiku_d[i] << ']';

		}
	}
	else
	{
		paichuli(paiku_n1,17);
		paixvchuli(paiku_n1,17);
		paishu(jipai_n1,15);
		cout << endl;
		cout << "您的牌为：" << "   ";
		for (int i = 0; i <17; i++)
		{
			cout << '[' << paiku_n1[i] << ']';

		}
	}




	//判牌
	if (jipai_n1[13] && jipai_n1[14])
		pailei_n1[11] = 3;
	//判断炸弹
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n1[i] == 4)
		{
			pailei_n1[10] = 2;
		}
	}
	//判断三顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_n1[i] == 3) && (jipai_n1[i + 1] == 3) && (jipai_n1[i + 2] == 3))
		{
			pailei_n1[9] = 1;
		}
	}
	//判断双顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_n1[i] == 2) && (jipai_n1[i + 1] == 2) && (jipai_n1[i + 2] == 2))
		{
			pailei_n1[8] = 1;
		}
	}
	//判断单顺子
	for (int i = 2; i < 9; i++)
	{
		if ((jipai_n1[i] == 1) && (jipai_n1[i + 1] == 3) && (jipai_n1[i + 2] == 1) && (jipai_n1[i + 3] == 1) && (jipai_n1[i + 4] == 1))
		{
			pailei_n1[7] = 1;
		}
	}
	//判断四带一对二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n1[i] == 2) && (jipai_n1[j] == 2) && (pailei_n1[10] == 2))
			{
				pailei_n1[6] = 1;
			}
	}
	//判断四带一对一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n1[i] == 1) && (jipai_n1[j] == 1) && (pailei_n1[10] == 2))
			{
				pailei_n1[5] = 1;
			}
	}
	//判断三带二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n1[i] == 2) && (jipai_n1[j] == 3))
			{
				pailei_n1[4] = 1;
			}
	}
	//判断三带一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n1[i] == 1) && (jipai_n1[j] == 3))
			{
				pailei_n1[3] = 1;
			}
	}
	//判断三牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n1[i] == 3)
		{
			pailei_n1[2] = 1;
		}
	}
	//判断双牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n1[i] == 2)
		{
			pailei_n1[1] = 1;
		}
	}
	//判断单牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n1[i] == 1)
		{
			pailei_n1[0] = 1;
		}
	}
	for (int i = 0; i < 17; i++)
	{
		if (paiku_n2[i] < 52) {
			paiku_n2[i] = paiku_n2[i] % 13;
		}

	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16 - i; j++)
		{
			if (pdycl(paiku_n2[j]) < pdycl(paiku_n2[j + 1]))
			{
				int temp = paiku_n2[j];
				paiku_n2[j] = paiku_n2[j + 1];
				paiku_n2[j + 1] = temp;
			}

		}

	}
	for (int i = 1; i < 16; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (paiku_n2[j] = i)
			{
				jipai_n2[i - 1] += 1;
			}
		}
	}
	//判断农民2的牌类
	//先判断王炸
	if (jipai_n2[13] && jipai_n2[14])
		pailei_n2[11] = 3;
	//判断炸弹
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n2[i] == 4)
		{
			pailei_n2[10] = 2;
		}
	}
	//判断三顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_n2[i] == 3) && (jipai_n2[i + 1] == 3) && (jipai_n2[i + 2] == 3))
		{
			pailei_n2[9] = 1;
		}
	}
	//判断双顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_n2[i] == 2) && (jipai_n2[i + 1] == 2) && (jipai_n2[i + 2] == 2))
		{
			pailei_n2[8] = 1;
		}
	}
	//判断单顺子
	for (int i = 2; i < 9; i++)
	{
		if ((jipai_n2[i] == 1) && (jipai_n2[i + 1] == 3) && (jipai_n2[i + 2] == 1) && (jipai_n2[i + 3] == 1) && (jipai_n2[i + 4] == 1))
		{
			pailei_n2[7] = 1;
		}
	}
	//判断四带一对二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n2[i] == 2) && (jipai_n2[j] == 2) && (pailei_n2[10] == 2))
			{
				pailei_n2[6] = 1;
			}
	}
	//判断四带一对一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n2[i] == 1) && (jipai_n2[j] == 1) && (pailei_n2[10] == 2))
			{
				pailei_n2[5] = 1;
			}
	}
	//判断三带二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n2[i] == 2) && (jipai_n2[j] == 3))
			{
				pailei_n2[4] = 1;
			}
	}
	//判断三带一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_n2[i] == 1) && (jipai_n2[j] == 3))
			{
				pailei_n2[3] = 1;
			}
	}
	//判断三牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n2[i] == 3)
		{
			pailei_n2[2] = 1;
		}
	}
	//判断双牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n2[i] == 2)
		{
			pailei_n2[1] = 1;
		}
	}
	//判断单牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_n2[i] == 1)
		{
			pailei_n2[0] = 1;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (paiku_d[i] < 52) {
			paiku_d[i] = paiku_d[i] % 13;
		}

	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19 - i; j++)
		{
			if (pdycl(paiku_d[j]) < pdycl(paiku_d[j + 1]))
			{
				int temp = paiku_d[j];
				paiku_d[j] = paiku_d[j + 1];
				paiku_d[j + 1] = temp;
			}

		}

	}
	for (int i = 1; i < 16; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (paiku_d[j] = i)
			{
				jipai_d[i - 1] += 1;
			}
		}
	}
	//判断地主的牌类
	//先判断王炸
	if (jipai_d[13] && jipai_d[14])
		pailei_d[11] = 3;
	//判断炸弹
	for (int i = 0; i < 13; i++)
	{
		if (jipai_d[i] == 4)
		{
			pailei_d[10] = 2;
		}
	}
	//判断三顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_d[i] == 3) && (jipai_d[i + 1] == 3) && (jipai_d[i + 2] == 3))
		{
			pailei_d[9] = 1;
		}
	}
	//判断双顺子
	for (int i = 2; i < 11; i++)
	{
		if ((jipai_d[i] == 2) && (jipai_d[i + 1] == 2) && (jipai_d[i + 2] == 2))
		{
			pailei_d[8] = 1;
		}
	}
	//判断单顺子
	for (int i = 2; i < 9; i++)
	{
		if ((jipai_d[i] == 1) && (jipai_d[i + 1] == 3) && (jipai_d[i + 2] == 1) && (jipai_d[i + 3] == 1) && (jipai_d[i + 4] == 1))
		{
			pailei_d[7] = 1;
		}
	}
	//判断四带一对二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_d[i] == 2) && (jipai_d[j] == 2) && (pailei_d[10] == 2))
			{
				pailei_d[6] = 1;
			}
	}
	//判断四带一对一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_d[i] == 1) && (jipai_d[j] == 1) && (pailei_d[10] == 2))
			{
				pailei_d[5] = 1;
			}
	}
	//判断三带二
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_d[i] == 2) && (jipai_d[j] == 3))
			{
				pailei_d[4] = 1;
			}
	}
	//判断三带一
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
			if ((jipai_d[i] == 1) && (jipai_d[j] == 3))
			{
				pailei_d[3] = 1;
			}
	}
	//判断三牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_d[i] == 3)
		{
			pailei_d[2] = 1;
		}
	}
	//判断双牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_d[i] == 2)
		{
			pailei_d[1] = 1;
		}
	}
	//判断单牌
	for (int i = 0; i < 13; i++)
	{
		if (jipai_d[i] == 1)
		{
			pailei_d[0] = 1;
		}
	}





























//出牌
	cout << "等待地主开始出牌" << endl;












	//结束
	cout << "                               **********************************************************" << endl;
	cout << "                               *恭喜" <<      '1' <<"获得胜利，奖励斗地积分1分"           "*" << endl;
	cout << "                               **********************************************************" << endl;
	system("pause");


}
