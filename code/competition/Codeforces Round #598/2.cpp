#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        int date[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> date[i];
        }
        int tmp=0;
        for (int i = 0; i < n; i++)
        {
            int min = 9999;
            int mint = -1;
            for (int i = tmp; i < n;i++){
                if(min>date[i]){
                    mint=i;
                    min=date[i];
                }
            }if(mint!=-1){
            for(int i=mint;i>tmp;i--){
                swap(date[i],date[i-1]);
            }
            if(tmp==mint)
            tmp++;
            else
            tmp=mint;
            //printf("%d\n",tmp);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << date[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}