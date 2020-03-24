#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll find_two(ll n)
{
    ll ret = 0;
    while(n)
    {
        ret += n/2;
        n /= 2;
    }
    return ret;
}

ll find_five(ll n)
{
    ll ret = 0;
    while(n)
    {
        ret += n/5;
        n /= 5;
    }
    return ret;
}

int main()
{
    ll t, caseno = 0, n, r, p, q, two, five, ctemp, ptemp;
    cin >> t;
    while(t--)
    {
        cin >> n >> r >> p >> q;
        two = find_two(n) - find_two(r) - find_two(n-r);
        five = find_five(n) - find_five(r) - find_five(n-r);

        ptemp = p;
        ctemp = 0;
        while(ptemp % 2 == 0)
        {
            ptemp /= 2;
            ctemp++;
        }
        two += ctemp*q;

        ptemp = p;
        ctemp = 0;
        while(ptemp%5 == 0)
        {
            ptemp /= 5;
            ctemp++;
        }
        five += ctemp*q;

        cout << "Case " << ++caseno << ": " << min(two, five) << endl;
    }
}
