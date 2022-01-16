#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, mn, cnt, ans;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        mn = cnt = ans = 0;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'B')
                cnt++;
            else
                cnt--;

            if(mn > cnt)
            {
                ans = i+1;
                mn = cnt;
            }
        }

        cout << ans << "\n";
    }
}

