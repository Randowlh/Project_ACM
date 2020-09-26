#include <bits/stdc++.h>
using namespace std;
struct link_list{
    struct node{
        node* nxt;
        int v;
        node(int a):v(a){}
    };
    node * head=NULL;
    void ins(int v){
        node* tmp=new node(v);
        tmp->nxt=head;
        head=tmp;
    }
    int pop(){
        if(head==NULL)
            return -1;
        int ans=head->v;
        node *tmp=head;
        head=head->nxt;
        delete tmp;
    }
    void reverse(){
        node* thead=NULL;
        while(head!=NULL){
            node* tmp=new node(head->v);
            node *tt=head;
            head=head->nxt;
            delete tt;
            tmp->nxt=thead;
            thead=tmp;
        }
        head=thead;
    }
    void output(){
        node* p=head;
        while(p!=NULL){
            cout<<p->v<<' ';
            p=p->nxt;
        }
        cout<<endl;
    }
}a;
int main(){
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        a.ins(tmp);
    }
    a.output();
    a.reverse();
    a.output();
}