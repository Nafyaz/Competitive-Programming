#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, a[100009], pos, ans;

    for(i = 0; i < 100009; i++)
        a[i] = 2*i + i*(i-1)/2*3;

    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        while(n > 1)
        {
            pos = lower_bound(a, a + 100009, n+1) - a;
            ans ++;
            n -= a[pos-1];
        }

        cout << ans << endl;
    }

}
