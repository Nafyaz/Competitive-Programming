#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, p = 100003;

    cin >> n >> m;
    cout << p << " " << p << endl;

    for(i = 1; i <= n-2; i++)
    {
        cout << i << " " << i+1 << " 1\n";
        m--;
    }

    cout << n-1 << " " << n << " " << p-n+2 << endl;
    m--;

    for(i = 1; i <= n && m; i++)
    {
        for(j = i+2; j <= n && m; j++)
        {
            cout << i << " " << j << " " << p+1 << endl;
            m--;
        }
    }
}
