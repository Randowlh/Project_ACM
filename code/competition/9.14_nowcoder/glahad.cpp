#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int book[110];
int date[110];
int n;
int main(){
cin>>n;
    for(int i=0;i<n;i++){
        cin>>date[i];
    }
    int ans=0;
    int flag=0;
    sort(date,date+n);
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=i;j<n;j++){
            if(book[j]==0&&date[j]%date[i]==0){
                book[j]=1;
                flag=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}