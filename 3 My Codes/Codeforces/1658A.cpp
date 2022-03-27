#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, prev, ans;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        prev = -1;
        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(prev == -1)
                {
                    prev = i;
                    continue;
                }
                else
                {
                    if(i - prev == 2)
                        ans += 1;
                    else if(i - prev == 1)
                        ans += 2;
                    prev = i;
                }
            }
        }

        cout << ans << "\n";
    }
}
