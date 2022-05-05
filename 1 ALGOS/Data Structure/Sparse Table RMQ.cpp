#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005], sparse[100005][20], Log[100005];

ll findMin(ll st, ll ed)
{
    k = Log[ed-st+1];
    return min(sparse[st][k], sparse[ed - (1 << k) + 1][k]);
}

int main()
{
    Log[1] = 0;
    for(i = 2; i <= 100005; i++)
        Log[i] = Log[i>>1] + 1;

    ll n, i, j;
    for(i = 0; i <= n; i++)
    {
        cin >> a[i];
        sparse[i][0] = a[i];
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1LL << j) - 1 < n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);
    }

    ll q, k;
    cin >> q;

    while(q--)
    {
        cin >> i >> j;
        
        cout << findMin(i, j) << endl;
    }
}
