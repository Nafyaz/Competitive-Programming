//okay, first of all, this is one of the shittiest codes in my life
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, a, ans = 0;
    cin >> l >> r >> a;

    while(1)
    {
        if(l == 0 || (r == 0 && a == 0))
            break;
        l--;

        if(r > 0)
            r--;
        else
            a--;

        ans += 2;
    }

    while(1)
    {
        if(r == 0 || (l == 0 && a == 0))
            break;

        r--;
        if(l > 0)
            l--;
        else
            a--;

        ans += 2;
    }

    ans += (a - a%2);

    cout << ans;
}
