#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, m, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        m = n-1;
        for(i = 0; m>1; i++) m /= 2;
        m <<= i;

        for(i = 1; i < m; i++)
            cout << i << "\n";
        cout << "0\n";
        for(i = m; i < n; i++)
            cout << i << "\n";
    }
}
