#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int str[100000];
int tail;
int main(){
    for(int i=1;i<=5478;i++){
      
        str[tail]=i*i;
        tail++;
    }
    int n;
    while (cin>>n)
    {   
        int tmp=0;
        for(int i=0;i<tail;i++){
            if(str[i]>n){
                if(n+i>=str[i])
                n++;
                printf("%d\n",n+i);
                break;
            }
        }
    }
    return 0;
    

}