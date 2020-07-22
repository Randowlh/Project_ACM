#include<bits/stdc++.h>
using namespace std;
int date[110000];
int n, l, c;
bool ck(int v1,int v2){
    if(v1<=v2)
        return false; 
    if((l-1.0)/(long double)l<v2/(long double)v1)
        return true;
    return false;
}
int main(){
  
    cin >> n >> l >> c;
    for (int i = 1; i <= n;i++)
        cin >> date[i];
    sort(date + 1, date + n + 1);
    for (int i = 1; i <= n;i++){

    }
}