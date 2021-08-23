#include<bits/stdc++.h>
using namespace std;

int n, m, alive[200005], ans;
int upcount[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, u, v, q, type;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
        alive[i] = 1;

    for(i = 0; i < m; i++)
    {
        cin >> u >> v;

        if(u > v)
            swap(u, v);

        alive[u] = 0;
        upcount[u]++;
    }

    for(i = 1; i <= n; i++)
        ans += alive[i];

    cin >> q;
    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> u >> v;

            if(u > v)
                swap(u, v);

            upcount[u]++;

            if(alive[u])
            {
                alive[u] = 0;
                ans--;
            }
        }

        else if(type == 2)
        {
            cin >> u >> v;

            if(u > v)
                swap(u, v);

            upcount[u]--;

            if(!upcount[u])
            {
                alive[u] = 1;
                ans++;
            }
        }

        else
            cout << ans << "\n";
    }
}
