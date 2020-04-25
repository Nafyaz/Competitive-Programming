#include<bits/stdc++.h>
using namespace std;
int a[200009], pre[400009];
int main()
{
    int i, j, k, n, t, l, r, s, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(i = 0; i <= 2*k + 1; i++)
            pre[i] = 0;

        for(i = 0, j = n-1; i < j; i++, j--)
        {
            pre[2] += 2;
            pre[2*k+1] -= 2;

            l = min(a[i], a[j]) + 1;
            r = max(a[i], a[j]) + k;
            s = a[i] + a[j];

            pre[l]--;
            pre[r+1]++;

            pre[s]--;
            pre[s+1]++;
        }

        ans = n/2;
        for(i = 2; i <= 2*k; i++)
        {
            pre[i] += pre[i-1];
            ans = min(ans, pre[i]);
        }

        cout << ans << endl;
    }
}
