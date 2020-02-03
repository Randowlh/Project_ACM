#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int tree[100010];
void work(){
    int n;
    cin>>n;
    memset(tree,inf,sizeof(tree));
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        int now=1;
        while(true){
            if(tree[now]==inf){
                tree[now]=tmp;
                break;
            }
            if(tree[now]<tmp){
                now*=2;
                now++;
                continue;
            }else{
                now*=2;
                continue;
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
    string tmp;
    int a;
    cin>>a;
    cin>>tmp;
    if(tmp=="is"){
        cin>>tmp;
        cin>>tmp;
        if(tmp=="parent"){
            cin>>tmp;
            int b;
            cin>>b;
            int now=1;
            while(true){
                if(tree[now]==a){
                    break;
                }
                if(tree[now]<a){
                    now*=2;
                    now++;
                    continue;
                }else{
                    now*=2;
                    continue;
                }
            }
            if(tree[now*2]==b||tree[now*2+1]==b){
                cout<<"Yes"<<endl;
            }else
            {
                cout<<"No"<<endl;
            }
            
        }else
        if(tmp=="left"){
            cin>>tmp;
            cin>>tmp;
            int b;
            cin>>b;
            int now=1;
            while(true){
                if(tree[now]==b){
                    break;
                }
                if(tree[now]<b){
                    now*=2;
                    now++;
                    continue;
                }else{
                    now*=2;
                    continue;
                }
            }
            if(a==tree[now*2]){
                cout<<"Yes"<<endl;
            }else cout<<"No"<<endl;
        }else
        if(tmp=="right"){
            cin>>tmp;
            cin>>tmp;
            int b;
            cin>>b;
            int now=1;
            while(true){
                if(tree[now]==b){
                    break;
                }
                if(tree[now]<b){
                    now*=2;
                    now++;
                    continue;
                }else{
                    now*=2;
                    continue;
                }
            }
            if(a==tree[now*2+1]){
                cout<<"Yes"<<endl;
            }else cout<<"No"<<endl;
        }else{
            cin>>tmp;
            cin>>tmp;
            if(tree[1]==a){
                cout<<"Yes"<<endl;
            }else cout<<"No"<<endl;
        }
        
    }else{
        cin>>tmp;
        int b;
        cin>>b;
        cin>>tmp;
        cin>>tmp;
        if(tmp=="on"){
            cin>>tmp;
            cin>>tmp;
            cin>>tmp;
            int now=1;
            int lv=1;
            while(true){
                if(tree[now]==b){
                    break;
                }
                if(tree[now]<b){
                    now*=2;
                    now++;
                    lv++;
                    continue;
                }else{
                    now*=2;
                    lv++;
                    continue;
                }
            }
            int b=1;
            b<<=lv-1;
            int e=1;
            e<<=lv;
            int fl=1;
            for(int i=b;i<e;i++){
                if(tree[i]=='a'){
                    fl=0;
                    cout<<"Yes"<<endl;
                }
            }
            if(fl)
            cout<<"No"<<endl;
        }else{
            cin>>tmp;
            int now=1;
            int fl=0;
            while(true){
                if(tree[now]==b){
                    break;
                }
                if(tree[now]<b){
                    now*=2;
                    now++;
                    fl=1;
                    continue;
                }else{
                    now*=2;
                    fl=-1;
                    continue;
                }
            }
            if(tree[now+fl]==a){
                cout<<"Yes"<<endl;
            }else cout<<"No"<<endl;
        }
    }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
/*
5
2 4 1 3 0
8
2 is the root
1 and 4 are siblings
3 and 0 are on the same level
2 is the parent of 4
3 is the left child of 4
1 is the right child of 2
4 and 0 are on the same level
100 is the right child of 3
*/