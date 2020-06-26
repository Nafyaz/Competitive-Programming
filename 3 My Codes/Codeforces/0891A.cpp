#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, a[2009], g = 0, cnt = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
        if(a[i] == 1)
            cnt++;
    }

    if(g != 1)
    {
        cout << -1;
        return 0;
    }
    if(cnt)
    {
        cout << n-cnt;
        return 0;
    }

    int mn = INT_MAX;
    for(i = 0; i < n; i++)
    {
        g = 0;
        for(j = i; j < n; j++)
        {
            g = __gcd(g, a[j]);
            if(g == 1)
            {
                mn = min(mn, j-i + n-1);
                break;
            }
        }
    }

    cout << mn;
}

