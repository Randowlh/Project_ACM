#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int tmp;
int lenth;
int tn;
int ansmin;
int ansmax;
int main(){
    scanf("%d",&n);
    for(int q=0;q<n;q++){
        ansmax=0;
        ansmin=0;
        scanf("%d%d",&lenth,&tn);
        for(int i=0;i<tn;i++){
            scanf("%d",&tmp);
            ansmax=max(ansmax,max(tmp,lenth-tmp));            
            ansmin=max(ansmin,min(tmp,lenth-tmp));
        }
        printf("%d %d\n",ansmin,ansmax);
    }
    return 0;
}
