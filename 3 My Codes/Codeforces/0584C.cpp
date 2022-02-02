#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, t1, t2, i, j;
    string s1, s2, ans;

    cin >> n >> t >> s1 >> s2;

    ans = string(n, '.');

    t2 = t1 = t;
    for(i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
        {
            if(t1)
            {
                ans[i] = s2[i];
                t1--;
            }
            else if(t2)
            {
                ans[i] = s1[i];
                t2--;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
        else
            ans[i] = s1[i];
    }

    for(i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
        {
            if(t1 < t2)
            {
                ans[i] = (ans[i] - 'a' + 1)%26 + 'a';
                if(ans[i] == s1[i])
                    ans[i] = (ans[i] - 'a' + 1)%26 + 'a';

                t2--;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(t1 && t2 && s1[i] == s2[i])
        {
            ans[i] = (ans[i] - 'a' + 1)%26 + 'a';
            t1--;
            t2--;
        }
    }

    if(t1 || t2)
        cout << -1;
    else
        cout << ans;
}
