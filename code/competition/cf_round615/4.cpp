#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    int fr;
    int now;
    bool operator<(node a){
        return fr<a.fr;
    }
};
map<int,int> s;
int x;
int mix;
void fenpei(int tmp){
    if((tmp-x)>=0&&(s.count(tmp-x)==0)){
            s[tmp-x]=tmp;
            //cout<<tmp-x<<'s'<<endl;
                if(tmp-x==mix){
                while(true){
                    mix++;
                    if(s.count(mix)==0)
                    break;
                }
            }
            
        }else if(s.count(tmp)==0){
            s[tmp]=tmp;
          //  cout<<tmp<<'s'<<endl;
            if(tmp==mix){
                while(true){
                    mix++;
                    if(s.count(mix)==0)
                    break;
                }
            }
        }
            else if(s[tmp]>tmp){
                int t=s[tmp];
                s[tmp]=tmp;
                fenpei(t);
        }
        else if(s.count(((tmp+x)))==0){
            s[(tmp+x)]=tmp;
          //  cout<<tmp+x<<'a'<<endl;
            if((tmp+x)==mix){
                while(true){
                    mix++;
                    if(s.count(mix)==0)
                    break;
                }
            }
        }else if(s[(tmp+x)]>tmp){
             int t=s[(tmp+x)];
            s[(tmp+x)]=tmp;
            fenpei(t);
        }   
        return ;
}
void work(){
    int q;
    cin>>q>>x;
    //set<node> s;
    int tmp;
     mix=0;
    // s[4]=1;
    for(int i=0;i<q;i++){
        scanf("%d",&tmp);
        fenpei(tmp);
        printf("%d\n",mix);
    }
    return;
}
int main(){
    s.clear();
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}