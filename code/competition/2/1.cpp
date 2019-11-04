#include<cstdio>
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
	if (b)
            while((a %= b) && (b %= a));
	return a + b;
}
int main(){
    int n;
    cin>>n;
    int  a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a==1||b==1){
            printf("Finite\n");
        }else{
            if(GCD(a,b)!=1){
                printf("Infinite\n");
            }else{
                printf("Finite\n");
            }
        }
    }
    return 0;
}