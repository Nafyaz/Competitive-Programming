#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            for(j = 1; j <= i; j++)
                cout << "()";

            for(j = 1; j <= n-i; j++)
                cout << '(';
            for(j = 1; j <= n-i; j++)
                cout << ')';
            cout << "\n";
        }
    }
}
