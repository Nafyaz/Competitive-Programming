#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m, a, b, c, i, num, denum, d;
    string s;
    map<pair<ll, ll>, ll> freq;
    pair<ll, ll> p[200005];

    scanf("%lld", &m);

    for(i = 0; i < m; i++)
    {
        scanf("\n(%lld+%lld)/%lld", &a, &b, &c);

        num = a + b;
        denum = c;
        d = __gcd(num, denum);

        num /= d;
        denum /= d;

        p[i] = {num, denum};
        freq[{num, denum}]++;
    }

    for(i = 0; i < m; i++)
        cout << freq[p[i]] << " ";
}
