#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, a, n, flag, cnt[55];

    cin >> t;

    while(t--)
    {
        cin >> n;

        memset(cnt, 0, sizeof cnt);

        for(i = 0; i < n; i++)
        {
            cin >> a;
            while(a)
            {
                if(a <= n)
                {
                    cnt[a]++;
                    break;
                }
                a /= 2;
            }
        }

        flag = 1;
        for(i = n; i >= 1; i--)
        {
            if(cnt[i] == 0)
            {
                flag = 0;
                break;
            }

            cnt[i]--;
            cnt[i/2] += cnt[i];
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
