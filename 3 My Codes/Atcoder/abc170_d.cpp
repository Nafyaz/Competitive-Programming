#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int a[200009], cnt[1000009];

int main()
{
    int n, i, j;
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    for(i = 0; i < n; i++)
    {
        if(cnt[a[i]] != 0)
        {
            cnt[a[i]] = 2;
            continue;
        }

        for(j = 1; a[i] * j <= a[n-1]; j++)
            cnt[a[i] * j]++;
    }

    int ans = 0;
    for(i = 0; i < n; i++)
    {
        if(cnt[a[i]] == 1)
            ans++;
    }

    cout << ans;
}
