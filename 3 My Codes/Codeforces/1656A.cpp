#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, a, mnVal, mnIdx, mxVal, mxIdx;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mnVal = INT_MAX;
        mxVal = INT_MIN;
        for(i = 1; i <= n; i++)
        {
            cin >> a;

            if(a < mnVal)
            {
                mnVal = a;
                mnIdx = i;
            }
            if(a > mxVal)
            {
                mxVal = a;
                mxIdx = i;
            }
        }

        cout << mnIdx << " " << mxIdx << "\n";
    }
}
