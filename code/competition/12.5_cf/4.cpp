#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> ans;
int ae[4];
long long tols=0;
bool sv(int s)
{   
    int a[4];
    int tol=0;
    for(int i=0;i<=3;i++){
        a[i]=ae[i];
        tol+=ae[i];
    }
    vector<int> tmp;
    int flag=0;
    for (int i = s; i >= 0; i--)
    {
        if(a[i]>0){
            a[i]--;
            tol--;
            tmp.push_back(i);
        }else{
            flag=i+1;
            break;
        }
    }
    int now=flag;
    while(tol>0){
        if(now>=1&&a[now-1]>0){
            now--;
            a[now]--;
            tol--;
            tmp.push_back(now);
        }else if(now<3&&a[now+1]>0){
            now++;
            a[now]--;
            tol--;
            tmp.push_back(now);
        }else{
           return false;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<tmp.size();i++){
        printf("%d ",tmp[i]);
    }
    cout<<endl;
    return true;
}
int main()
{
  //  int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> ae[i];
        tols+=ae[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (sv(i))
        {
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}