#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, l, r, i, ans;

    cin >> n;

    while(n--)
    {
        cin >> l >> r;

        ans = 0;
        for(i = log2(r); i >= 0; i--)
        {
            if((r&(r+1)) == 0)
            {
                ans |= r;
                break;
            }

            if((l&(1LL << i)) == (r&(1LL << i)))
                ans |= l&(1LL << i);
            else
            {
                ans |= (1LL << i) - 1;
                break;
            }

            l &= ~(1LL << i);
            r &= ~(1LL << i);
        }

        cout << ans << "\n";
    }
}
