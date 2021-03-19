#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("chess.in", "r", stdin);

    ll t, n, k, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        k++;
        ll temp = n/k;
        ans = n + 2*n*temp;
        ans = ans - temp*(temp+1)*k;

        cout << n*n - ans << "\n";
    }
}
