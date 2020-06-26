#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll l[100009], a[100009];

int main()
{
    ll n, m, i, b, mx, total = 0;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> l[i];
        total += l[i];
    }

    if(total < n)
    {
        cout << -1;
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        a[i] = i;
        if(i + l[i] - 1 >= n)
        {
            cout << -1;
            return 0;
        }
    }

    mx = n-1;
    for(i = n-1; i >= 0; i--)
    {
        if(a[i] + l[i] - 1 >= mx)
            break;
        a[i] = mx - l[i] + 1;
        mx = a[i] - 1;
    }

    for(i = 0; i < m; i++)
        cout << a[i] + 1 << " ";
}
