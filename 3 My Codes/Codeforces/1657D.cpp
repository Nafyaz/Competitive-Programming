#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Unit
{
public:
    ll c, d, h, dh;

    bool operator<(const Unit& u)
    {
        if(dh != u.dh)
            return (dh > u.dh);
        return c < u.c;
    }

    bool cmp(const Unit&u, const ll dhNew)
    {
        if()
    }
};

ll D, H;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, C, x, i;
    Unit units[300005];

    cin >> n >> C;

    for(i = 0; i < n; i++)
    {
        cin >> units[i].c >> units[i].d >> units[i].h;
        units[i].dh = units[i].d * units[i].h;
    }

    sort(units, units+n);

//    for(i = 0; i < n; i++)
//        cout << units[i].c << " " << units[i].d << " " << units[i].h << "\n";

    cin >> m;
    while(m--)
    {
        cin >> D >> H;
        for(x = 1; x <= 100; x++)
        {

        }
    }
}
