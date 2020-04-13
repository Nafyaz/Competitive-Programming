//Modified a little bit
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, t, l, r, i, j, pos, part[100009];
    part[0] = 0;

    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        for(i = 1; i < n; i++)
        {
            part[i] = part[i-1] + n - i;

        }

        for(i = l; i <= r; i++)
        {
            if(i == n*(n-1)+1)
            {
                cout << 1 << " ";
                continue;
            }


            if(i%2 == 1)
            {
                j = (i+1)/2;
                pos = lower_bound(part, part+n, j) - part;
                cout << pos << " ";
            }
            else
            {
                j = i/2;
                pos = lower_bound(part, part+n, j) - part;
                cout << pos + (j - part[pos-1]) << " ";
            }
        }
        cout << endl;
    }
}
