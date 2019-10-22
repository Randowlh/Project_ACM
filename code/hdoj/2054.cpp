#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
bool cmp(string a, string b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i <a.size();i++){
            if(a[i]!='0'&&a[i]!='-'){
                flag1=1;
                break;
            }
        }
        for (int i = 0; i <b.size();i++){
            if(b[i]!='0'&&b[i]!='-'){
                flag1=1;
                break;
            }
        }
    if(flag1==0&&flag2==0){
        return true;
    }else{
        return false;
    }
    }
}
int main()
{   string zro;
    zro="0";
    string a, b;
    while (cin >> a >> b)
    {   int fu1=0;
        int fu2=0;
        string da, db, za, zb;
        da.clear();
        db.clear();
        za.clear();
        zb.clear();
        int flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '.')
            {
                flag = 1;
            }else if(a[i]=='-'){
                fu1=1;
            }
            else
            {
                if (flag)
                {
                    da.push_back(a[i]);
                }
                else
                {
                    za.push_back(a[i]);
                }
            }
        }
        flag = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == '.')
            {
                flag = 1;
            }else if(b[i]=='-'){
                fu2=1;
            }
            else
            {
                if (flag)
                {
                    db.push_back(b[i]);
                }
                else
                {
                    zb.push_back(b[i]);
                }
            }
        }
        if (da.empty())
        {
            da.push_back('0');
        }
        if (db.empty())
        {
            db.push_back('0');
        }
        if (za.empty())
        {
            za.push_back('0');
        }
        if (zb.empty())
        {
            zb.push_back('0');
        }
        if(fu1!=fu2){
            //if(cmp(za,zro)&&cmp(da,zro)&&cmp(zb,zro)&&cmp(db,zro)){
             //   printf("YES\n");
            //}else{
                printf("NO\n");
            //}
        }else
        if (cmp(zb, za) && cmp(da, db))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
    return 0;
}