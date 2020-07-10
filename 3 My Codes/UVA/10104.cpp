#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int& x, int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = egcd(b, a%b, x1, y1);

    x = y1;
    y = x1 - a/b*y1;

    return d;
}

int main()
{
    int a, b, d, x, y;
    while(cin >> a >> b)
    {
        d = egcd(a, b, x, y);
        cout << x << " " << y << " " << d << endl;
    }
}
