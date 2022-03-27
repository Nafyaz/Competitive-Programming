#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, r;

    cin >> a >> b >> r;

    if(min(a, b) < 2*r)
        cout << "Second";
    else
        cout << "First";
}
