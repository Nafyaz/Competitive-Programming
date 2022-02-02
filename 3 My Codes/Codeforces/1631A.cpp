#include<bits/stdc++.h>
using namespace std;

int a[102];
int b[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, mxa, mxb;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        mxa = mxb = 0;
        for(i = 0; i < n; i++)
        {
            if(a[i] > b[i])
                swap(a[i], b[i]);

            mxa = max(mxa, a[i]);
            mxb = max(mxb, b[i]);
        }

        cout << mxa*mxb << "\n";
    }
}
