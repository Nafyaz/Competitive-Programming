#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n == 1)
        return 0;

    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n, m, i, j, d;
    cin >> n >> m;

    for(d = n-1; !is_prime(d); d++);

    cout << d << " " << d << endl;

    for(i = 1; i <= n-2; i++)
    {
        cout << i << " " << i+1 << " 1\n";
        m--;
    }

    cout << n-1 << " " << n << " " << d-n+2 << endl;
    m--;

    for(i = 1; i <= n && m; i++)
    {
        for(j = i+2; j <= n && m; j++)
        {
            cout << i << " " << j << " 12345678\n";
            m--;
        }
    }
}
