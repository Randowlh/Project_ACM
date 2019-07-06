#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<cstring>
	using namespace std;
	class Person {
	public:
		Person(string a, string b, string  c) :m_A(a), m_B(b), m_C(c) {}
		void PrintPerson() {
			cout << "现在共有三位玩家：" << m_A << "和" << m_B << "和" << m_C << endl;
		}
	private:
		string m_A;
		string  m_B;
		string  m_C;
	};
	int max(int a, int b, int c) {
		int max;
		max = ((a > b ? a : b) > c ? max : c);
    return max;
	};
	int main(){
		int arr[3];
    memset(arr,0,sizeof(arr));
		int i;
		srand((unsigned)time(NULL));//调用time函数来获取随机数
		for (i = 0; i < 3; i++)
		{
			arr[i] = rand() % 4;
			cout << arr[i] << endl;
			int maxs=max(arr[0], arr[1], arr[2]);
			if (arr[0] == maxs) { cout << "地主是张三" << endl; }
			else if (arr[1] == maxs) { cout << "地主是李四"<<endl; }
			else cout<<"地主是王五"<<endl;
			Person p("张三", "李四", "王五");
			p.PrintPerson();
			system("pause");

			return 0;
		}
}
