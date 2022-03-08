#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d, m, x, y;

    cin >> n >> d >> m;

    while(m--)
    {
        cin >> x >> y;

        if(y < -x+d || y > x+d || y < x-d || y > -x+2*n-d)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
