#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, i, x, cur, ans, flag;
    map<ll, ll> cnt;

    cin >> n >> m;

    cnt[0]++;
    ans = flag = cur = 0;
    for(i = 0; i < n; i++)
    {
        cin >> x;

        if(x > m)
            cur++;
        else if(x < m)
            cur--;
        else
            flag = 1;

        if(!flag)
            cnt[cur]++;
        else
            ans += cnt[cur] + cnt[cur-1];
    }

    cout << ans;
}
