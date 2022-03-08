#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, A, B;
ll a[200005];

ll cntAvengers(ll i, ll j)
{
    ll cnti, cntj;

    cnti = lower_bound(a, a+k, i) - a;
    cntj = upper_bound(a, a+k, j) - a;

    return cntj - cnti;
}

ll func(ll i, ll j)
{
    ll cnt = cntAvengers(i, j);

    if(cnt == 0)
        return A;

    if(i == j)
        return B*cnt;

    ll mid = (i+j)/2;

    return min(B*cnt*(j-i+1), func(i, mid)+func(mid+1, j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    cin >> n >> k >> A >> B;

    for(i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    sort(a, a+k);

    cout << func(0, (1<<n)-1);
}
