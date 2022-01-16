#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b, c;

    cin >> n;

    while(n--)
    {
        cin >> a >> b;

        c = cbrt(a*b);

        if(c*c*c == a*b && a%c == 0 && b%c == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
