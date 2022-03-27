//follow tenkei

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll l, r, x, n;

    cin >> l >> r;

    for(x = 1; x <= r; x *= 10);

    x--;

    n = x/2;

    if(r < n)
        n = r;
    else if(l > n)
        n = l;

    cout << n*(x - n);
}
