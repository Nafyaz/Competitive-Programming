#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n;
        if(n == 2)
        {
            cout << "-1 -1\n";
            cout << "-1 -1\n";
            continue;
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j)
                    cout << -1 << " ";
                else
                    cout << 1 << " ";
            }
            cout << "\n";
        }
    }
}
