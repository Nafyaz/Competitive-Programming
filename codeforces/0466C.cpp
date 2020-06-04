#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, i, a[500009], lft[500009], rgt[500009], total;
ll cleft[500009], cright[500009];
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        lft[i] = lft[i-1] + a[i];
        total += a[i];
    }
    if(n < 3 || total % 3 != 0)
    {
        cout << 0;
        return 0;
    }

    for(i = n; i >= 1; i--)
        rgt[i] = rgt[i+1] + a[i];

    for(i = 1; i <= n - 2; i++)
    {
        if(lft[i] == total/3)
            cleft[i] = cleft[i-1] + 1;
        else
            cleft[i] = cleft[i-1];
    }

    ll ans = 0;
    for(i = n; i > 2; i--)
    {
        if(rgt[i] == total/3)
            ans += cleft[i-2];
    }

//    for(i = 0; i <= n+1; i++)
//        cout << cright[i] << " ";
//
////    ll ans = 0;
////    for(i = 0; i <= n; i++)
////        ans += cleft[i]*cright[i+2];
////
    cout << ans;
}
