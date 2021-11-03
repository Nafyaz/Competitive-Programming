#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, x, pref[100005], prev, total, ans, i;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> x >> s;

        prev = 0;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
                pref[i] = ++prev;
            else
                pref[i] = --prev;
        }

        total = pref[n-1];

        ans = 0;
        if(x == 0)
            ans++;

        if(total)
        {
            for(i = 0; i < n; i++)
            {
                if((x - pref[i]) % total == 0 && (x - pref[i]) / total >= 0)
                    ans++;
            }

            cout << ans << "\n";
            continue;
        }

        for(i = 0; i < n; i++)
        {
            if(pref[i] == x)
            {
                ans = -1;
                break;
            }
        }

        cout << ans << "\n";
    }
}
