#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        while(k > 3)
        {
            cout << "1 ";
            n--;
            k--;
        }

        if(n%2 == 1)
            cout << "1 " << n/2 << " " << n/2 << "\n";
        else if(n%4 == 2)
            cout << "2 " << n/2-1 << " " << n/2-1 << "\n";
        else
            cout << n/2 << " " << n/4 << " " << n/4 << "\n";
    }
}
