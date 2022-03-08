#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    pair<ll, ll> p[3];

    cin >> t;

    while(t--)
    {
        cin >> p[0].ff >> p[0].ss;
        cin >> p[1].ff >> p[1].ss;
        cin >> p[2].ff >> p[2].ss;

        if(p[0].ss == p[1].ss && p[2].ss < p[0].ss)
            cout << abs(p[0].ff - p[1].ff) << "\n";
        else if(p[0].ss == p[2].ss && p[1].ss < p[0].ss)
            cout << abs(p[0].ff - p[2].ff) << "\n";
        else if(p[1].ss == p[2].ss && p[0].ss < p[1].ss)
            cout << abs(p[1].ff - p[2].ff) << "\n";
        else
            cout << "0\n";
    }
}
