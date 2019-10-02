    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cmath>
    #include<cstring>
    #include<string>
    using namespace std;
    char a1[1000],b1[1000];
    int a[1000],b[1000],c[1000];
    int main()
    {
        while(scanf("%s",a1)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%s",b1);
        if(a1[0]==48&&b1[0]==48)
        {
            cout<<"0"<<endl;
            return 0;
        }
        int lena=strlen(a1),lenb=strlen(b1);
        for(int i=0;i<lena;i++)
        {
            a[lena-i-1]=int(a1[i]-48);
        }
        for(int i=0;i<lenb;i++)
        {
            b[lenb-i-1]=int(b1[i]-48);
        }
        int m=max(lena,lenb);
        for(int i=0;i<m;i++)
        {
            c[i]+=a[i]+b[i];
            while(c[i]>=10)
            {
                c[i+1]++;
                c[i]-=10;
            }
        }
        m++;
        while(c[m]==0)    m--; 
        for(int i=m;i>=0;i--){
            if(c[i]%2==0){
                cout<<0;
            }else cout<<1;
        }
        cout<<endl;
        }
        return 0;
}
