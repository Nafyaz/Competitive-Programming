#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll p[200005];
ll pre[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        if(p[i] > m)
            pre[i] = pre[i-1] + 1;
        else if(p[i] < m)
            pre[i] = pre[i-1] - 1;
    }

    for(i = 0; i <= n; i++)
    {
        if(i < mIdx)
            Left[pre[i]]++;
        if(i >= mIdx)
            Right[pre[i]]++;
    }

    ans = 0;
    for(auto u : Left)
    {
        if(Right.find(u.ff) != Right.end())
            ans += u.ss * Right[u.ff];
        if(Right.find(u.ff+1) != Right.end())
            ans += u.ss * Right[u.ff+1];
    }

    cout << ans;
}
