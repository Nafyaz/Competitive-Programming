#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, X, i, c[102];

    cin >> n >> X;

    for(i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i] *= n-i;
    }

    sort(c, c+n);

    for(i = 0; i < n; i++)
    {
        if(c[i] > X)
            break;
        X -= c[i];
    }

    cout << i;
}
