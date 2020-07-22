#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, x = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        if(a != i)
            x++;
    }

    cout << (x <= 2? "YES" : "NO");

}
