#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m, x1, x2, y1, y2;
    int x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
        x = abs(x1 - x2);
        y = abs(y1 - y2);

        cout << 2*(n - x)*(m - y) - (n - 2*x)*(m - 2*y) << endl;
    }
}
