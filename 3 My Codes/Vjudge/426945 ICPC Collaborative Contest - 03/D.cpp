#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, i, ans;
    int a[100009];

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        ans = a[1];
        for(i = 1; i < n; i++)
            a[i] -= a[1];
    }
}
