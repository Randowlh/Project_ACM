#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int abs(int a){
    if(a<0){
        return -a;
    }else return a;
}
struct node{
    int a;
    bool operator<(node a){
        return abs(this->a)>abs(a.a);
    }
} date[100000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>date[i].a;
    }
    sort(date,date+n);
    for(int i=0;i<n;i++){
        cout<<date[i].a<<' ';
    }
    cout<<endl;
    return 0;
}