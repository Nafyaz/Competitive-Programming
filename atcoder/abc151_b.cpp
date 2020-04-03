#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, m, i;
    cin >> n >> k >> m;
    int a[n-1], total = 0;

    for(i = 0; i < n-1; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    if(m*n > total + k)
        cout << -1;
    else
        cout << max(0, m*n - total);
}

