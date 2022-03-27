#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t, a[2] = {1, 2}, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n%3 == 1)
            i = 0;
        else
            i = 1;

        while(n)
        {
            cout << a[i];
            n -= a[i];
            i = (i+1)%2;
        }
        cout << "\n";
    }
}
