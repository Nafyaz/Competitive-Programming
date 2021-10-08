#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a[3], d, m;

    cin >> t;

    while(t--)
    {
        cin >> a[0] >> a[1] >> a[2] >> m;

        sort(a, a+3, greater<int>());

        if(m > a[0]+a[1]+a[2]-3 || m < max(0, a[0]-1-a[1]-a[2]))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
