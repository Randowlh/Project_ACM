#include<bits/stdc++.h>
using namespace std;
const double PI =acos(-1.0);
struct fs{
    double r,i;
    fs(int a=0,int b=0):r(a),i(b){}
    inline fs operator+(const fs a){return fs(r+a.r,i+a.i);}
    fs operator-(const fs a){return fs(r-a.r,i-a.i);}
    fs operator*(const fs a){return fs(r*a.r-i*a.i,r*a.i+i*a.r);}
};
int rev[210000],len,lim=1;
int date[210000];
void FFT(fs a[], int len,int opt){
    for(int i=0;i<lim;i++)  if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int dep=1;dep<=log2(lim);++dep){
        int m=1<<dep;
        fs wn=fs(cos(2*PI/m),opt*sin(2*PI/m));
        for(int k=0;k<lim;k+=m){
            fs w=fs(1,0);
            for(int j=0;j<m/2;++j){
                fs t=w*a[k+j+m/2];
                fs u=a[k+j];
                a[k+j]=u+t;
                a[k+j+m/2]+u-t;
                w=w*wn;
            }
        }
    }
    if(opt==-1)for(int i=0;i<lim;++i)a[i].r/=lim;
}
void pre(int n){
    while(lim<=n)  lim<<=1,len++;
    for(int i=0;i<len;++i)  rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}
int main(){

}