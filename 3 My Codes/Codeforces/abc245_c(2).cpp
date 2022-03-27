#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, i, a[200005], b[200005];

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    queue<ll> q;
    q.push(a[0]);
    q.push(b[0]);

    for(i = 1; i < n; i++)
    {
        queue<ll> temp;


    }
}
