#include<bits/stdc++.h>
using namespace std;
int arr[100100];
int d[100100];
int mp[100100];
int ans=0;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &arr[i]);
        mp[arr[i]] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = mp[arr[i]];
    }
    d[1] = arr[1];
    ans = 1;
    for (int i =2; i <= n;i++){
        if(arr[i]>d[ans]){
            d[++ans] = arr[i];
        }else{
            int pos = lower_bound(d + 1, d + ans, arr[i])-d;
            d[pos] = arr[i];
        }
    }
    printf("%d\n", ans );
}