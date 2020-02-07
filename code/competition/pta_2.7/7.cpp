#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    string s;
   // getline(cin, tmp);
    int g=0,p=0,l=0,t=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='g'||s[i]=='G')
			g++;
		if(s[i]=='p'||s[i]=='P')
			p++;
		if(s[i]=='l'||s[i]=='L')
			l++;
		if(s[i]=='t'||s[i]=='T')
			t++;
	}
	while(g>0||p>0||l>0||t>0)
	{
		if(g>0)
		{
			cout<<"G";
			g--;
		}
		if(p>0)
		{
			cout<<"P";
			p--;
		}
		if(l>0)
		{
			cout<<"L";
			l--;
		}
		if(t>0)
		{
			cout<<"T";
			t--;
		}
	}
    return;
}
int main()
{
    // freopen("in.txt","r",stdin);
    //cin>>t;
    work();
    return 0;
}