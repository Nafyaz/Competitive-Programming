#include<bits/stdc++.h>
using namespace std;

long double h, c, t;

long double func(long long x)
{
    return (h+c)/2 + (h-c)/2/x;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> h >> c >> t;
        if(t <= (h+c)/2)
        {
            cout << 2 << endl;
            continue;
        }
        if(t >= h)
        {
            cout << 1 << endl;
            continue;
        }

        long long ans = INT_MAX, l = 1, r = INT_MAX, mid;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(func(mid) < t)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }

        if(ans%2 == 0)
        {
            cout << (abs(func(ans + 1) - t) < abs(func(ans - 1) - t)? ans + 1: ans - 1) << endl;
        }
        else
            cout << ans << endl;

    }
}
