#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, n, i, a, total;

    cin >> t;

    while(t--)
    {
        cin >> n;

        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            total += a;
        }

        if(total % n == 0)
            cout << "0\n";
        else
            cout << "1\n";
    }
}
