#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

struct point{
int x, y;
};

int X(point c, point a, point b) // ac X ab
{
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);

}

point p[1000];

int main()
{
	point a, b, c, sa, sb;
	int flag, n;

	while(cin >> n, n)
	{
		int i;
		for(i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		p[n].x = p[0].x;
		p[n].y = p[0].y;
		p[n+1].x = p[1].x;
		p[n+1].y = p[1].y;

		flag = true;

		for(i = 0; i < n; i++)
			if(X(p[i+2], p[i], p[i+1]) >= 0)
			{
				flag = false;
				break;
			}
		if(flag)
			cout << "convex" << endl;
		else cout << "concave" << endl;
	}


	return 0;
}
