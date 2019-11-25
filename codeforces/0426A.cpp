#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, s, i, total = 0;
    cin >> n >> s;
    int a[n];

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    sort(a, a+n);
    total -= a[n-1];

    total > s? cout << "NO" : cout << "YES";
}
