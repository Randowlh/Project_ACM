#include<iostream>
using namespace std;
int main()
{
    int x,y,z;
    for (x=0;x<=20;x++)
    {
        for(y=0;y<=33;y++)
        {
            z=100-x-y;
            if (z%3==0&&x*5+y*3+z/3==100)
                cout<<"公鸡："<<x<<"，母鸡："<<y<<"，小鸡："<<z<<endl;
        }

    }
    return 0;
}
