#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, s, x, y;
    cin >> n >> m >> s;
    cout << ((n-1)%s+1) * ((m-1)%s+1) * ((n+s-1)/s) * ((m+s-1)/s);
}
