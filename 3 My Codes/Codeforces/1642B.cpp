#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, types;

    cin >> T;

    while(T--)
    {
        cin >> n;

        set<ll> s;
        for(i = 1; i <= n; i++)
        {
            cin >> a;
            s.insert(a);
        }

        types = s.size();

        for(i = 1; i <= n; i++)
            cout << max(i, types) << " ";

        cout << "\n";
    }
}
