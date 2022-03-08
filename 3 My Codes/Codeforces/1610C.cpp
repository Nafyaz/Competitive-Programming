#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005], b[200005];

bool canTake(int k)
{
    int i, rich = k-1, poor = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] >= rich && poor < k && b[i] >= poor)
        {
            poor++;
            rich--;
        }
    }

    return (poor == k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, i, l, r, mid, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i] >> b[i];

        l = 0;
        r = n;

        while(l <= r)
        {
            mid = (l+r)/2;
            if(canTake(mid))
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }

        cout << ans << "\n";
    }
}
