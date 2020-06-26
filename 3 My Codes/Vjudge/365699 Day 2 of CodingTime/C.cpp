#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, sum = 0;
    cin >> n;
    int m[n];

    for(i = 0; i < n; i++)
    {
        cin >> m[i];
        sum += m[i];
    }

    int x = n - (sum - sum/n*n), y = sum/n;

    sort(m, m+n);

    int ans = 0;
    for(i = 0; i < n; i++)
    {
        if(i < x)
            ans += abs(y-m[i]);
        else
            ans += abs(m[i] - y - 1);
    }

    cout << ans/2;
}
