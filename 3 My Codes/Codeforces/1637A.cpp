#include<bits/stdc++.h>
using namespace std;

int a[10004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        cout << (is_sorted(a, a+n)? "NO\n" : "YES\n");
    }
}
