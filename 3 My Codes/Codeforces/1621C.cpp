#include<bits/stdc++.h>
using namespace std;

int p[10004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, x, prev, val;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            p[i] = -1;
        }

        for(i = 1; i <= n; i++)
        {
            if(p[i] == -1)
            {
                x = i;
                cout << "? " << x << endl;
                cin >> prev;

                while(p[prev] == -1)
                {
                    cout << "? " << x << endl;
                    cin >> val;

                    p[prev] = val;

                    prev = val;
                }
            }
        }

        cout << "! ";
        for(i = 1; i <= n; i++)
            cout << p[i] << " ";
        cout << endl;
    }
}
