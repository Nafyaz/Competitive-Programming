#include <bits/stdc++.h>
#define floop(i, n, m) for (int i = m; i < n; i++)
#define ll long long int
#define input(a)      \
    for (auto &i : a) \
    cin >> i
#define ascsort(a) sort(a.begin(), a.end())
#define fillvec(a)    \
    for (auto &i : a) \
        cin >> i;
#define sumwhole(a, n) accumulate(a.begin(), a.end(), 0)
#define printvec(a)  \
    for (auto i : a) \
        cout << i << " ";
#define PB push_back
#define nl cout << "\n"
#define spc " "

using namespace std;
ll bintodec(string n)
{

    int l = n.size();
    ll b = 1;
    ll d = 0;
    for (ll i = l - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            d += b;
        }
        b *= 2;
    }

    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        fillvec(a);


        vector<string> b(n);
        ll lenmax = INT_MIN;
        floop(i, n, 0)
        {
            b[i] = bitset<35>(a[i]).to_string();
            ll len = to_string(stoll(b[i])).size();
            if (len > lenmax)
                lenmax = len;

        }

        string c = "";
        for (ll i = 34; i >= 34 - lenmax + 1; i--)
        {
            ll c0 = 0, c1 = c0;
            for (int j = 0; j < n; j++)
            {

                b[j][i] == '0' ? c0++ : c1++;

            }
            if (c0 == c1 & c0 != 0)
            {
                c.PB('0');
            }
            else if (c0 > c1)
            {
                c.PB('0');
            }
            else if (c1 > c0)
            {
                c.PB('1');
            }

        }


        reverse(c.begin(), c.end());

        cout << bintodec(c);
        nl;
    }
}
