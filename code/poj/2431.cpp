#include<queue>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct node
{
    int l;
    int p;
    bool operator<(const node a)const{
        return this->l<a.l;
    }
}date[10010];
priority_queue<int> pq;
int n;
int l;
int p;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&date[i].l,&date[i].p);
    }
    date[n].l=l;
    date[n].p=0;
    cin>>l>>p;
    int pos=0;
    int ans=0;
    sort(date,date+n);
    for(int i=0;i<=n;i++){





        
        if(pos>=l){
            printf("%d",ans);
            return 0;
        }else{
            p-=date[i].l-pos;
            pos=date[i].l;
            if(p<0){
                while(!pq.empty()&&p<0){
                    p+=pq.top();
                    pq.pop();
                    ans++;
                }
            }
            if(p<0){
                printf("-1\n");
                return 0;
            }
            pq.push(date[i].p);
        }
    }
            printf("%d",ans);
            return 0;
    

    
}