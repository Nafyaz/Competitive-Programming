#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
stack<ll> rems[200005];
stack<ll> Free;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, val, k, cnt, ans;

    cin >> n >> m;
    cnt = n/m;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        rems[a[i]%m].push(i);
    }

    ans = 0;
    for(i = 0; i < m; i++)
    {
        while(rems[i].size() > cnt)
        {
            Free.push(rems[i].top());
            rems[i].pop();
        }

        while(rems[i].size() < cnt && !Free.empty())
        {
            val = Free.top();
            rems[i].push(val);
            Free.pop();

            k = ((i - a[val])%m + m)%m;
            ans += k;
            a[val] += k;
        }
    }

    for(i = 0; i < m; i++)
    {
        while(rems[i].size() > cnt)
        {
            Free.push(rems[i].top());
            rems[i].pop();
        }

        while(rems[i].size() < cnt && !Free.empty())
        {
            val = Free.top();
            rems[i].push(val);
            Free.pop();

            k = ((i - a[val])%m + m)%m;
            ans += k;
            a[val] += k;
        }
    }

    cout << ans << "\n";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
