#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, c, d, d2Cnt = 0, d1Min, d2Max, totalChange = 0;

    cin >> n;

    d1Min = INT_MAX;
    d2Max = INT_MIN;
    for(i = 1; i <= n; i++)
    {
        cin >> c >> d;

        if(d == 1)
            d1Min = min(d1Min, totalChange);
        else
            d2Max = max(d2Max, totalChange);

        totalChange += c;
        d2Cnt += (d == 2);
    }

    if(d2Cnt == 0)
        cout << "Infinity";
    else if(d1Min <= d2Max)
        cout << "Impossible";
    else
        cout << 1899 - d2Max + totalChange;
}
