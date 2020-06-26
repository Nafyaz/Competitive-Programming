#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, x[4], y[4];
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    if(n == 1)
        cout << -1;
    else if(n == 2)
    {
        if(x[0] != x[1] && y[0] != y[1])
            cout << abs(x[0] - x[1]) * abs(y[0] - y[1]);
        else
            cout << -1;
    }
    else
    {
        int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
        for(i = 0; i < n; i++)
        {
            xmin = min(xmin, x[i]);
            xmax = max(xmax, x[i]);

            ymin = min(ymin, y[i]);
            ymax = max(ymax, y[i]);
        }

        cout << abs(xmax - xmin) * abs(ymax - ymin);
    }
}
