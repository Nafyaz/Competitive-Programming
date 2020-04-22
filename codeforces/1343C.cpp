#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, i, n, a, type, mxa, mxi, nxt, cnt, sum;
    cin >> t;
    while(t--)
    {
        nxt = mxi = -1;
        cnt = sum = 0;
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> a;
            type = (a>0);
            if(nxt == -1)
            {
                nxt = type;
                cnt++;
                mxa = a;
            }
            else if(nxt != type)
            {
                nxt = type;
                cnt++;
                sum += mxa;
                mxa = a;
                mxi = max(mxi, i);
            }
            else
                mxa = max(mxa, a);
//            cout << mxa << " " << sum << endl;
        }

        sum += mxa;

        cout << sum << endl;
    }
}
