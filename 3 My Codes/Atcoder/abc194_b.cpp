#include<bits/stdc++.h>
using namespace std;

int a[1003], b[1003];

int main()
{
    int n, i, j, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    ans = INT_MAX;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                ans = min(ans, a[i] + b[j]);
            else
                ans = min(ans, max(a[i], b[j]));
        }
    }

    cout << ans;
}

