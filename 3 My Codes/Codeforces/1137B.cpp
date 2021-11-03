#include<bits/stdc++.h>
using namespace std;

int LPS[500005];
void KMP(string s)
{
    int i, j, n = s.size();

    LPS[0] = 0;
    for(i = 1; i < n; i++)
    {
        j = LPS[i-1];

        while(j > 0 && s[i] != s[j])
            j = LPS[j-1];

        if(s[i] == s[j])
            j++;

        LPS[i] = j;
    }
}

int main()
{
    int i, j, cnt[2] = {0};
    string s, t;

    cin >> s >> t;

    KMP(t);

    for(i = 0; i < s.size(); i++)
    {
        cnt[0] += (s[i] == '0');
        cnt[1] += (s[i] == '1');
    }

    for(i = 0, j = 0; i < s.size(); i++)
    {
        if(cnt[t[j] - '0'])
        {
            cnt[t[j] - '0']--;
            cout << t[j];
            j++;
            if(j == t.size())
                j = LPS[t.size() - 1];
        }
        else
            cout << ((t[j] - '0') ^ 1);
    }
}
