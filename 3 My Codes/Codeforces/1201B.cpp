#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i, n, a, total = 0, mx = -1;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        total += a;
        mx = max(a, mx);
    }

    cout << (total%2 == 0 && total - mx >= mx? "YES" : "NO");
}
