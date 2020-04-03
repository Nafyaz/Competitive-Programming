#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, k, w, d, c;
    cin >> n >> k;
    w = n/2;
    d = w/(k+1);
    c = d*k;
    w = c+d;

    cout << d << " " << c << " " << n-w;
}

