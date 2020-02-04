#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    string tmp;
    getline(cin, tmp);
    cout << tmp << endl;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == '?'||tmp[i]==','||tmp[i]=='\'')
        {  
            tmp.insert(i, " ");
            tmp.insert(i + 2, " ");
            i+=3;
        }
    }
    stringstream ss(tmp);
    vector<string> v;
    string t;
    while (ss >> t)
    {
        v.push_back(t);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != "I")
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] <= 'Z' && v[i][j] >= 'A')
                {
                    v[i][j] -= 'A';
                    v[i][j] += 'a';
                }
            }
        }
    }
    int fl = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "you"&&fl!=0)
        {   
            v[i - 1] = "I";
            if(fl==1){
                v[i]="can";
            }else{
                v[i]="could";
            }
            fl=0;
            continue;
        }
        if (v[i] == "?")
        {
            v[i] = "!";
            fl = 0;
            continue;
        }
        if (v[i] == "I")
        {
            v[i] = "you";
            fl = 0;
            continue;
        }
        if (v[i] == "can")
        {
            fl = 1;
            continue;
        }
        if (v[i] == "could")
        {
            fl = 2;
            continue;
        }
        if (v[i] == "me")
        {
            v[i] = "you";
            fl = 0;
            continue;
        }
    }
    cout<<"AI: ";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i<v.size()-1&&(v[i+1]!="'"&&v[i+1]!=","&&v[i+1]!="!"&&v[i]!="'"&&v[i]!=",")){
            cout<<' ';
        }
    }
    cout<<endl;
    return;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    getchar();
    while (t--)
    {
        work();
    }
    return 0;
}
/*
Hello ?
AI: hello!
 Good to chat   with you
AI: good to chat with you
can   you speak Chinese?
AI: I can speak chinese!
Really?
AI: really!
Could you show me 5
AI: I could show you 5
What Is this prime? I,don 't know
AI: what Is this prime! you,don't know
*/