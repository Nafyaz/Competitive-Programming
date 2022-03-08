#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if(n%2 == 0)
        {
            cout << "YES\n";
            for(i = 0; i < n; i += 2)
            {
                for(j = 1; j <= 2*k; j += 2)
                    cout << i*k + j << " ";
                cout << "\n";
                for(j = 2; j <= 2*k; j += 2)
                    cout << i*k + j << " ";
                cout << "\n";
            }
        }
        else if(k == 1)
        {
            cout << "YES\n";
            for(i = 1; i <= n; i++)
                cout << i << "\n";
        }
        else
            cout << "NO\n";
    }
}
