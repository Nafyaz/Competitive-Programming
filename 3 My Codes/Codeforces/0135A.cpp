#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    a[n-1] = (a[n-1] == 1? 2 : 1);

    sort(a, a+n);

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
