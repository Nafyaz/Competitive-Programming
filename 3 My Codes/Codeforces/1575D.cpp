#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, sz, flag, cnt = 1, ans = 0;

    string s, t;
    cin >> s;

    sz = s.size();

    if(sz == 1)
    {
        cout << 0;
        return 0;
    }

    flag = 0;
    for(i = 0; i < sz-2; i++)
    {
        if(s[i] == '_')
        {
            if(i)
                cnt *= 10;
            else
                cnt *= 9;
        }
        if(s[i] == 'x')
            flag = 1;
    }

    t = s;
    for(i = 0; i <= 9; i++)
    {
        for(j = 0; j < sz; j++)
        {
            if()
        }
    }
}
