#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b)
{
    return a*b/__gcd(a, b);
}

int main()
{
    long long n, m, mx = 0, i, j, k, a[5];
    cin >> n;
    for(i = 0; i < 5 && n - i > 0; i++)
        a[i] = n-i;
    m = i;

    for(i = 0; i < m; i++)
    {
        for(j = i; j < m; j++)
        {
            for(k = j; k < m; k++)
                mx = max(mx, lcm(lcm(a[i], a[j]), a[k]));
        }
    }

    cout << mx;
}

