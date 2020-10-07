
#include <bits/stdc++.h>
using namespace std;
string s ,a[150],b[150],flag[150];
bool judge(int pos)
{
    if(a[pos].size()<=1) return false;
    if(a[pos][0]>='a' && a[pos][0] <='z') return false;
    for(int i=1;i<a[pos].size();++i)
    {
        if( a[pos][i]>='A' && a[pos][i] <='Z') return false;
    }
    return true;
}
int main()
{
    freopen("abbreviation.in","r",stdin);
    freopen("abbreviation.out","w",stdout);
    while(getline(cin,s))
    {
        int ida=0 , idb=0;
        b[0]="";
        for(int i=0;i<s.size();)
		//a记录单词  b记录间隔符号和空格
        {
            a[++ida]="";
            for( ;i<s.size();++i)
            {
                if(isalpha(s[i]))   a[ida]+=s[i];
                else break;
            }
            b[++idb]="";
            for( ; i<s.size();++i)
            {
                if(!isalpha(s[i])) b[idb]+=s[i];
                else break;
            }
        }
        b[idb+1]="";
 
        for(int i=1;i<=ida;++i)
        {
        	//如果a单词符合缩写的话 flag存a[i]的第一个字母
            if(judge(i)) flag[i]=a[i][0];
            else flag[i]="";
        }
 
        for(int i=1;i<=ida;)
        {
            if(flag[i]!="")
            {
                string temp = flag[i];//存缩写
                for(int j=i+1;j<=ida;++j)
                {
                    if(b[j-1]==" " && flag[j] !="")
                    {
                        temp+=flag[j];
                    }
                    else
                    {
                        if(temp.size()>=2)//缩写放b中
                        {
                            b[i-1] +=temp+" (";
                            b[j-1] =")"+b[j-1];
                        }
                        i=j;
                        temp="";
                        break;
                    }
                }
                if(temp!="")
                {
                    if(temp.size()>=2)
                    {
                        b[i-1] +=temp+" (";
                        b[ida] =")"+b[ida];
                    }
                    i=ida+1;
                    temp="";
                }
            }
            else ++i;
        }
        if(b[0]!="") cout<<b[0];
        for(int i=1;i<ida;++i)
        {
            cout<<a[i]<<b[i];
        }
        if(b[ida]=="") cout<<a[ida]<<endl;
        else cout<<a[ida]<<b[ida]<<endl;
    }
    return 0;
}
