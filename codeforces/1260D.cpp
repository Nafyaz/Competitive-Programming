#include <bits/stdc++.h>
using namespace std;
int m, n, k, t, a[200009], l[200009], r[200009], d[200009];

bool check(int s)
{
    int i, t0 = 0, sa = a[s-1], spos = 0;
    vector<int> traps, disable;

    for(i = 1; i <= n; i++)
    {
        if(d[i] > s)
        {
            traps.push_back(i);
            disable.push_back()
        }
    }

    while(spos <= n)
    {
        if()
    }
}

int main()
{
    int i;
    cin >> m >> n >> k >> t;

    for(i = 0; i < m; i++)
        cin >> a[i];

    sort(a, a+n, greater<int>);

    for(i = 0; i < k; i++)
        cin >> l[i] >> r[i] >> d[i];

    int ans, low = 0, high = m, mid;
    while(low <= high)
    {
        mid = (low + high)/2;

    }
}
