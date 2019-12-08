#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, x, c[3] = {0};
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        c[x-1]++;
    }

    sort(c, c+3);
    cout << c[0] + c[1];
}
