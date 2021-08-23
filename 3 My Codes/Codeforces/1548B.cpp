#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll d[200005];
ll sparse[200005][20];
ll Log[200005];

bool is_ok(ll sz)
{
    if(sz == 0)
        return 1;

    ll i, j, k;
    for(i = 0; i + sz < n; i++)
    {
        j = i + sz - 1;
        k = Log[sz];

        if(__gcd(sparse[i][k], sparse[j - (1 << k) + 1][k]) != 1)
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, i, j, a, aprev, ans, low, high, mid;

    Log[1] = 0;
    for(i = 2; i < 200005; i++)
        Log[i] = Log[i>>1] + 1;


    cin >> t;

    while(t--)
    {
        cin >> n;


        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(i)
            {
                d[i-1] = abs(a - aprev);
                sparse[i-1][0] = d[i-1];
            }

            aprev = a;
        }

        for(j = 1; (1LL << j) < n; j++)
        {
            for(i = 0; i + (1LL << j) < n; i++)
                sparse[i][j] = __gcd(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);
        }

//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j <= 4; j++)
//                cout << setw(3) << sparse[i][j];
//            cout << "\n";
//        }

        low = 0;
        high = n-1;

        while(low <= high)
        {
            mid = (low + high) / 2;

            if(is_ok(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans + 1 << "\n";
    }
}
/*
6
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78
1
10
2
1 2
*/
