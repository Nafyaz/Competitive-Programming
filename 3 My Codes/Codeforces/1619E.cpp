#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int t, n, i, ans, cnt, smallerCnt;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        for(i = 0; i <= n; i++)
        {
            smallerCnt = lower_bound(a, a+n, i);

            if(smallerCnt < i)
            {
                cout << "-1 ";
                continue;
            }

            cnt = upper_bound(a, a+n, i) - lower_bound(a, a+n, i);
        }
    }
}
