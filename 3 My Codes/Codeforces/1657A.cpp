#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, x, y, sq;

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        sq = sqrt(x*x + y*y);

        if(x == 0 && y == 0)
            cout << "0\n";
        else if(sq*sq == x*x + y*y)
            cout << "1\n";
        else
            cout << "2\n";
    }
}
