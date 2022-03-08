#include<bits/stdc++.h>
using namespace std;

int par[100005];
//int p[100005];

int Find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    par[max(x, y)] = min(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, p, r, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            par[i] = i;

        r = 1;
        for(i = 1; i <= n; i++)
        {
            cin >> p;

            r = max(r, i);
            while(p > r)
            {
                Union(p, r);
                r++;
            }
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            if(Find(i) == i)
                ans++;
        }

        cout << ans << "\n";
    }
}
