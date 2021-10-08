#include<bits/stdc++.h>
using namespace std;

bool a[1000006];

void solve()
{
    int n, d, i, j, left, right, ans = -1, g;
    cin >> n >> d;

    g = __gcd(n, d);

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(i = 0; i < g; i++)
    {
        j = i;
        string s;
        while(1)
        {
            s.push_back('0' + a[j]);

            j = (j+d)%n;
            if(j == i)
                break;
        }

        if(s.find('0') == -1)
        {
            cout << -1 << "\n";
            return;
        }

        for(j = 0; j < s.size(); j++)
        {
            if(!j || s[j] == '0')
                left = 0;
            else
                left = left + 1;

            if(!j || s[s.size()-1-j] == '0')
                right = 0;
            else
                right = right + 1;

            ans = max({ans, left, right});
        }

        ans = max(ans, left + right);
    }

    cout << ans << "\n";
}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
