#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main()
{
    int n, m, x, i, s, sx, t = 0;
    cin >> n >> m >> x;
    for(i = 0; i < m; i++)
    {
        cin >> s;
        t += s;
        if(i == x-1)
            sx = s;
    }

    if(t < n)
    {
        cout << -1;
        return 0;
    }

    ld ans = 1;

    for(i = 1; i < sx; i++)
    {
        ans = ans*(t-n-i+1)/(t-i);
//        cout << i << " " << ans << endl;
    }

    cout << fixed;
    cout << setprecision(8) << 1 - ans << endl;
}
