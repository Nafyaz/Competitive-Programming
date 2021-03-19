#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, caseno = 0, n, m, i, j, ans, cnt[309];
    ll sub, prob[15];

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < 309; i++)
            cnt[i] = 0;

        for(i = 0; i < n; i++)
        {
            cin >> sub;
            cnt[sub]++;
        }
        for(i = 0; i < m; i++)
            cin >> prob[i];

        sort(prob, prob+m, greater<ll>());

        ans = 0;

        for(j = 300; j >= 0 && !cnt[j]; j--);

        for(i = 0; i < m; i++)
        {
            if(prob[i] == 0)
                continue;
            ans += j;
            ans += 20*(prob[i]-1);
            prob[i]--;
            cnt[j]--;

            for(;(!cnt[j] || prob[i]) && j >= 0; j--)
            {
                ll tmp = min(prob[i], cnt[j]);
                prob[i] -= tmp;
                cnt[j] -= tmp;
            }
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
