#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, k, i, a[30];
    string s, ans;
    int c;

    cin >> t;

    while(t--)
    {
        memset(a, 0, sizeof a);

        cin >> s >> k;

        for(i = 0; i < s.size(); i++)
            a[s[i] - 'a'] = 1;

        ans = "";
        c = 'a';

        for(i = 0; i < s.size(); i++)
        {
            if(k)
            {
                if(a[c - 'a'] == 1)
                    k--;

                ans.push_back(c);
                c++;
            }

            else
            {
                while(a[c - 'a'] == 1)
                    c++;

                ans.push_back(c);
                c++;
            }
        }

        if(c > 'z' + 1)
            cout << "NOPE\n";
        else
            cout << ans << "\n";
    }
}
