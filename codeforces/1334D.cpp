#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, t, l, r, i, j, pos, part[100009];
    part[0] = 0;
//    pre[0] = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        for(i = n-1; i > 0; i--)
        {
            part[n-i] = part[n-i-1] + i;
//            pre[n-i] = pre[n-i-1] + part[n-i];
        }

//        for(i = 0; i < n; i++)
//            cout << part[i] << " ";
//        cout << endl;
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
