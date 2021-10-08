#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define base 1000003
#define mod 100000007

vector<ll> a[10];
ll ans[10], b[100005][10];
set<ll> banned;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j, k, c, p, x, ansHash, ansSum, Hash, Sum, flag;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> c;
        ans[i] = c-1;

        while(c--)
        {
            cin >> x;
            a[i].push_back(x);
        }
    }

    cin >> m;
    for(i = 0; i < m; i++)
    {
        p = 1;
        Hash = 0;

        for(j = 0; j < n; j++)
        {
            cin >> b[i][j];
            b[i][j]--;
            Hash = (Hash + b[i][j]*p)%mod;
            p = (p*base)%mod;
        }

        banned.insert(Hash);
    }

    p = 1;
    ansHash = 0;
    for(i = 0; i < n; i++)
    {
        ansHash = (ansHash + ans[i]*p)%mod;
        p = (p*base)%mod;
    }

    if(banned.find(ansHash) == banned.end())
    {
        for(i = 0; i < n; i++)
            cout << ans[i]+1 << " ";
        return 0;
    }

    ansSum = 0;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            p = 1;
            Hash = Sum = 0;
            flag = 1;
            for(k = 0; k < n; k++)
            {
                if(j == k && b[i][k] > 0)
                {
                    Hash = (Hash + (b[i][k]-1)*p)%mod;
                    Sum += a[k][b[i][k]-1];
                }
                else if(j == k)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    Hash = (Hash + b[i][k]*p)%mod;
                    Sum += a[k][b[i][k]];
                }
                p = (p*base)%mod;
            }

            if(flag && Sum > ansSum && banned.find(Hash) == banned.end())
            {
//                cout << i << " " << j << " " << Hash << "\n b[i][k]: ";
                ansSum = Sum;
                for(k = 0; k < n; k++)
                {
//                    cout << b[i][k] << " ";
                    if(j == k)
                        ans[k] = b[i][k] - 1;
                    else
                        ans[k] = b[i][k];
                }
//                cout << "\n";
            }
        }
    }

    for(i = 0; i < n; i++)
        cout << ans[i]+1 << " ";
}
