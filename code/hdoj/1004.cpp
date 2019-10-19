#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int st[1010];
int tail;
string st1[1010];
int main()
{
    int n;
    string tmp;
    while (true)
    {
        tail = 0;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            int flag = 0;
            for (int j = 0; j < tail; j++)
            {
                if (st1[j] == tmp)
                {
                    flag = 1;
                    st[j]++;
                    break;
                }
            }
            if (flag == 0)
            {
                st[i] = 1;
                st1[tail] = tmp;
                tail++;
            }
        }
        int max = -1;
        int maxt = -1;
        for (int i = 0; i < tail; i++)
        {
            if (st[i] > max)
            {
                max = st[i];
                maxt = i;
            }
        }
        cout << st1[maxt] << endl;
    }
    return 0;
}