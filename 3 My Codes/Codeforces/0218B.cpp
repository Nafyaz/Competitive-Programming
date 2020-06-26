#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i, n, m, sum = 0;
    cin >> n >> m;
    long long a[m];

    for(i = 0; i < m; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    long long minans = 0, maxans = 0, tempn = n;
    sort(a, a+m);

    long long pass;

    for(i = 0; i < m; i++)
    {
        pass = min(tempn, a[i]);
        minans += a[i]*(a[i] + 1) / 2 - (a[i] - pass)*(a[i] - pass + 1) / 2;
        tempn -= pass;
    }

    tempn = sum - n;

    for(i = 0; i < m; i++)
    {
        pass = a[i] - min(tempn/(m-i), a[i]);
        maxans += a[i]*(a[i] + 1) / 2 - (a[i] -   pass)*(a[i] - pass + 1) / 2;
        tempn -= min(tempn/(m-i), a[i]);
    }

    cout << maxans << " " << minans;
}
