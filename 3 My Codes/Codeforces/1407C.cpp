#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, mxIdx, x, y;
    int p[10004];

    cin >> n;

    for(i = 2, mxIdx = 1; i <= n; i++)
    {
        cout << "? " << mxIdx << " " << i << "\n";
        cin >> x;
        cout << "? " << i << " " << mxIdx << "\n";
        cin >> y;

        if(x < y)
            p[i] = y;
        else
        {
            p[mxIdx] = x;
            mxIdx = i;
        }
    }

    p[mxIdx] = n;

    cout << "! ";
    for(i = 1; i <= n; i++)
        cout << p[i] << " ";
}
