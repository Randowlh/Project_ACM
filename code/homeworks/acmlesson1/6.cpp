#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int date[1010];
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>date[i];
        }
        sort(date,date+n,greater<int>());
        for(int i=0;i<n;i++){
            if(date[i]<0)
            break;
            for(int j=i+1;j<i+1+date[i]&&j<n;j++){
                date[j]--;
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(date[i]<0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}