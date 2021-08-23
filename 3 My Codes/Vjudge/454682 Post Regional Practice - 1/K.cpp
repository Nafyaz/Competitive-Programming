#include<bits/stdc++.h>
using namespace std;

bool bit(int x, int i)
{
    return ((x & (1 << i)) >> i);
}

int main()
{
    int t, n, u, v, ud, vd, i, j, mx, mxlen;

    cin >> t;

    while(t--)
    {
        cin >> n >> u >> v;

        ud = log2(u) + 1;
        vd = log2(v) + 1;

        for(i = ud-1, j = vd-1; i >= 0 && j >= 0; i--, j--)
        {
//            cout << i << " " << j << "\n";
//            cout << u << " " << v << "\n\n";

            if(bit(u, i) == bit(v, j))
            {
                u &= ~(1 << i);
                v &= ~(1 << j);
            }
            else
                break;

        }

        if(i > j)
        {
            mx = u;
            mxlen = i+1;
        }
        else if(i < j)
        {
            mx = v;
            mxlen = j+1;
        }
        else
        {
            mx = max(u, v);
            mxlen = i+1;
        }

        cout << ((n-mx) >> mxlen) << "\n";
    }
}
