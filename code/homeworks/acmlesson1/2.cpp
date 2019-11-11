#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
struct node{
    int bk;
    int fr;
    bool operator< (node a){
        return this->fr<a.fr;
    }
}date[100000];
*/
//int fr[100000];
//int bk[100000];
int flag[1000000];
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        int fr,bk;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++){
            flag[i]=0;
            cin>>fr>>bk;
            if(fr>bk){
                swap(fr,bk);
            }
            if(fr%2==0)
			   fr-=1;
			if(bk%2==1)
			   bk+=1;

            for(int i=fr;i<=bk;i++){
                flag[i]+=10;
            }
        }
        int tol=0;
        for(int i=0;i<1000000;i++){
            if(tol<flag[i]){
                tol=flag[i];
            }
        }
        cout<<tol<<endl;
    }
    return 0;
}