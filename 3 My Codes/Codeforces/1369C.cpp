#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[200009], w[200009];
vector<int> v[200009];

int main()
{
    ll t, i, j, n, k, l, h, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);

        for(i = 0; i < k; i++)
        {
            cin >> w[i];
            v[i].clear();
        }
        sort(w, w + k);

        h = n - 1;
        for(i = 0; i < k && w[i] == 1; i++)
        {
            v[i].push_back(a[h]);
            h--;
        }
        for(; i < k && w[i] == 2; i++)
        {
            v[i].push_back(a[h]);
            h--;
            v[i].push_back(a[h]);
            h--;
        }
        j = i;
        for(; i < k; i++)
        {
            v[i].push_back(a[h]);
            h--;
        }
        for(i = j; i < k; i++)
        {
            for(j = 1; j < w[i]; j++)
            {
                v[i].push_back(a[h]);
                h--;
            }
        }

        ans = 0;
        for(i = 0; i < k; i++)
            ans += v[i][0] + v[i].back();

        cout << ans << endl;
    }
}
