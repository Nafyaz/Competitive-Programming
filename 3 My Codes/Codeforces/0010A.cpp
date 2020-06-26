#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int n, p1, p2, p3, t1, t2, i, l, r, ans = 0, prevr, x, y, z;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    prevr = 0;
    for(i = 0; i < n; i++)
    {
        cin >> l >> r;

        ans += (r-l)*p1;

        if(i == 0)
        {
            prevr = r;
            continue;
        }

        x = min(t1, l-prevr);
        ans += p1*x;

        y = min(t2, l - (prevr + x));
        ans += p2*y;

        z = l - (prevr + x + y);
        ans += p3*z;

        prevr = r;
    }

    cout << ans;

}

