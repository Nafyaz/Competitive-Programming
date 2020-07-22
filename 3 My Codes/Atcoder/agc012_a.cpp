#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[300009], n, i;
    cin >> n;

    for(i = 0; i < 3*n; i++)
        cin >> a[i];

    sort(a, a+3*n);

    long long ans = 0;
    for(i = 3*n-2; i >= n; i -=2)
        ans = ans + a[i];

    cout << ans;
}
