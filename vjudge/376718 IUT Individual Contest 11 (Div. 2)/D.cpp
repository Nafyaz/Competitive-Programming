#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll j, p, q, d;
    while(cin >> j >> p >> q >> d)
    {
        q -= j;
        if(q < 0)
            q = ((q%d) + d)%d;

    }
}
