#include <cstdio>
#include <algorithm>
using namespace std;
struct note {
        int k;
        int s;
        bool operator < (const note& b) const {
                if(s<b.s)
                        return true;
                else if(s==b.s) {
                        if(k>=b.k)
                                return true;
                        else
                                return false;
                }
                else
                        return false;
        }

};
struct note ar[100000];
int main(){
        int n;
        int m;
        scanf("%d%d",&n,&m );
        for(int i=0; i<n; i++) {
                scanf("%d%d",&ar[i].k,&ar[i].s);
        }
        sort(ar,ar+n);
        printf("%d ",ar[n-m*3/2].s);
        int cnt=0;
        for(int i=n-1; i>=0; i--) {
                if(ar[n-m*3/2].s<=ar[i].s)
                        cnt++;
                else
                        break;
        }
        printf("%d\n",cnt );
        for(int i=n-1; i>n-1-cnt; i--) {
                printf("%d %d\n",ar[i].k,ar[i].s);
        }


        return 0;
}
