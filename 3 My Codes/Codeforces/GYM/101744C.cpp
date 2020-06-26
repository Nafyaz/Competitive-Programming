#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y;

    if(x > y)
        cout << 1 << " " << x - y << endl;
    else if(x < y)
        cout << 2 << " " << y - x << endl;

    x = min(x, y);
    y = min(x, y);

    while(x || y)
    {
        cin >> a >> b;
        if(a == 1)
            x -= b;
        else
            y -= b;

        cout << (a&1) + 1 << " " << b << endl;

        if(a == 1)
            y -= b;
        else
            x -= b;
    }
}

