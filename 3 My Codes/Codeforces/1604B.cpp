#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, a, prev, is_increasing;

    cin >> t;

    while(t--)
    {
        prev = 0;
        is_increasing = 1;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a <= prev)
                is_increasing = 0;
            prev = a;
        }

        if(n%2 == 1 && is_increasing == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
