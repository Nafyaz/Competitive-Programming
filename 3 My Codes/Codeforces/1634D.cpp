#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, diff, mxdiff, ansi, ansj;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mxdiff = -1;
        for(i = 3; i <= n; i++)
        {
            cout << "? 1 2 " << i << endl;
            cin >> diff;

            if(diff == -1)
                return 0;

            if(diff > mxdiff)
            {
                mxdiff = diff;
                ansi = i;
            }
        }

        mxdiff = -1;
        for(i = 1; i < n-1; i++)
        {
            cout << "? " << i << " " << n-1 << " " << n << endl;
            cin >> diff;

            if(diff == -1)
                return 0;

            if(diff > mxdiff)
            {
                mxdiff = diff;
                ansj = i;
            }
        }

        cout << "! " << ansi << " " << ansj << endl;
    }
}
