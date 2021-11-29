#include<bits/stdc++.h>
using namespace std;
#define N 1000006
#define ll long long

ll a[200005];
bool flag[N];

void sieve()
{
    ll i, j;
    flag[2] = 1;

    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i*i < N; i += 2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    sieve();
    ll t, i, n, e, step, l, r, lValid, rValid, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> e;

        for(i = 0; i < n; i++)
            cin >> a[i];

        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(!flag[a[i]])
                continue;


            for(l = i-e; l >= 0 && a[l] == 1; l -= e);
            for(r = i+e; r < n && a[r] == 1; r += e);

            lValid = (i-l)/e;
            rValid = (r-i)/e;

            ans += lValid * rValid - 1;
        }

        cout << ans << "\n";
    }
}
