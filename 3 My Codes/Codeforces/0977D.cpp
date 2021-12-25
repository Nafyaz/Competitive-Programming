#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[102], vis[102];
stack<ll> ans;

bool dfs(ll pos, ll i)
{
    vis[i] = 1;

    if(pos == n-1)
        return 1;

    for(ll j = 0; j < n; j++)
    {
        if(!vis[j] && (2*a[i] == a[j] || a[i] == 3*a[j]))
        {
            if(dfs(pos+1, j) == 1)
            {
                ans.push(a[j]);
                return 1;
            }
        }
    }

    vis[i] = 0;
    return 0;
}

int main()
{
    ll i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    for(i = 0; i < n; i++)
    {
        if(dfs(0, i) == 1)
        {
            ans.push(a[i]);

            while(!ans.empty())
            {
                cout << ans.top() << " ";
                ans.pop();
            }
            break;
        }
    }
}
