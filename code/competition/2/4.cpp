#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
struct edge{
    int w;
    int v;
    int u;
    bool operator<(const edge a){
        return this->w<a.w;
    }
} date[4000010];
int c[2010];
int k[2010];
int x[2010];
int y[2010];
int n;
long long dis(int i,int j){

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
}