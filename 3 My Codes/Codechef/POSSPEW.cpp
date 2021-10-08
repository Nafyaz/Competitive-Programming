#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, a[100005];
ll dist[100005];

void leftdist(ll i, ll d)
{
    if(dist[i] != -1 && dist[i] <= d)
        return;

    dist[i] = d;
    leftdist((i-1+n)%n, d+1);
}

void rightdist(ll i, ll d)
{
    if(dist[i] != -1 && dist[i] <= d)
        return;

    dist[i] = d;
    rightdist((i+1)%n, d+1);
}

int main()
{
    ll T, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            dist[i] = (a[i] == 0? -1 : 0);
        }

        for(i = 0; i < n; i++)
        {
            if(a[i])
            {
                leftdist((i-1+n)%n, 1);
                rightdist((i+1)%n, 1);
            }
        }

        ans = 0;
        for(i = 0; i < n; i++)
        {
            ans += a[i];

            if(dist[i] != -1 && dist[i] < k)
                ans += 2*(k - dist[i]);
        }

        cout << ans << "\n";
    }
}
