#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, d, m, n, i, ans, x[35], total;
    cin >> t;
    while(t--)
    {
        memset(x, 0, sizeof x);
        x[1] = 1;
        total = x[1];
        cin >> d >> m;
        n = log2(d) + 1;
        for(i = 2; i <= n; i++)
        {
            if(i == n)
                x[i] = (d - total + m);
            else
                x[i] = (x[i-1] << 1);
            total = (total + x[i]);
        }

        ans = 1;

        for(i = 0; i < 35; i++)
        {
//            cout << x[i] << " ";
            ans = ans*(x[i] + 1)%m;
        }

        cout << (m==1? 0 : (ans - 1 + m)%m) << endl;
    }
}
