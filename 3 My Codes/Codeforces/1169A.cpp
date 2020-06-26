#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, x, b, y, i;
    cin >> n >> a >> x >> b >> y;

    a--;
    x--;
    b--;
    y--;

    for(i = 0; i < n; i++)
    {
        if((a+i)%n == (b-i+n)%n)
        {
            cout << "YES";
            return 0;
        }
        if((a+i)%n == x || (b-i+n)%n == y)
            break;
    }

    cout << "NO";
}
