#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, a, b;
    cin >> t;
    while(t--)
    {
        cin >> n;
        a = b = 0;
        for(i = 1; i <= n; i++)
        {
            if(i < n/2 || i == n)
                a += (1 << i);
            else
                b += (1 << i);
        }
        cout << a-b << endl;
    }
}
