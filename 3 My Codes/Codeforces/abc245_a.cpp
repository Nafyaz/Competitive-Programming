#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, x, y;

    cin >> a >> b >> c >> d;

    x = a*60 + b;
    y = c*60 + d;

    cout << (x <= y? "Takahashi\n" : "Aoki\n");
}
