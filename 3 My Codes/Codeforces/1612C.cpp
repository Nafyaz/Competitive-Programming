#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt_stars(ll k, ll line)
{
    ll ret = 0;
    if(line <= k)
        return line*(line + 1)/2;

    ret += k*(k+1)/2;
    line -= k;

    ret += (k-1)*k/2 - (k-line-1)*(k-line)/2;
    return ret;
}

int main()
{
    ll t, k, x, low, high, mid, stars1, stars2, ans;

    cin >> t;

    while(t--)
    {
        cin >> k >> x;

        low = 1;
        high = 2*k-1;

        while(low <= high)
        {
            mid = (low+high)/2;

            stars1 = cnt_stars(k, mid-1);
            stars2 = cnt_stars(k, mid);

            if(stars2 < x || (stars1 < x && stars2 >= x))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << ans << "\n";
    }
}
