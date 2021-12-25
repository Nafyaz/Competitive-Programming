#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<pair<int, int>> v;
int quarrel[200005];
int ans[200005];

bool cmp(pair<int, int> p, pair<int, int> q)
{
    return p.ff < q.ff;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k, r, i, x, y;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> r;
        v.push_back({r, i});
    }

    while(k--)
    {
        cin >> x >> y;

        if(v[x-1].ff == v[y-1].ff)
            continue;

        if(v[x-1].ff < v[y-1].ff)
            swap(x, y);

        quarrel[x-1]++;
    }

    sort(v.begin(), v.end());

    for(i = 0; i < n; i++)
    {
        ans[v[i].ss] = lower_bound(v.begin(), v.end(), v[i], cmp) - v.begin() - quarrel[v[i].ss];
    }

    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
}
