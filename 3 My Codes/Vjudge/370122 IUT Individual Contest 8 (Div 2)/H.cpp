#include<bits/stdc++.h>
using namespace std;

int dig(int n)
{
    if(!n)
        return 0;
    return log10(n) + 1;
}

int main()
{
    int n, i, j, a[100009];
    string s, t, prev;
    a[0] = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> s;
        if(dig(a[i-1]) < s.size())
        {
            cout << "NO";
            return 0;
        }
        else if(dig(a[i-1]) > s.size())
        {
            for(j = 0; j < s.size(); j++)
            {
                if(s[j] == '?')
                {
                    if(!j)
                        s[j] = '1';
                    else
                        s[j] = '0'
                }
            }
            a[i] = stoi(s);
        }
        else
        {
            prev = to_string(a[i-1]);
            t = "";
            for(j = 0; j < s.size(); j++)
                t = t + (s[j] == '?'? prev[j] : s[j]);

            int flag = -1, idx;
            for(j = 0; j < s.size(); j++)
            {
                if(flag == -1 && t[j] != prev[j])
                {
                    flag = prev[j] > t[j];
                    idx = j;
                }
                else if(flag != -1 && s[j] == '?')
                    t[j] = '0';
            }
            if(flag == -1)
            {
                flag = 1;
                idx = s.size() - 1;
            }
            t = to_string(stoi(t.substr(0, idx+1)) + 1) + t.substr(idx+1, t.size() - idx - 1);
        }
        a[i] = stoi(t);
    }
}
