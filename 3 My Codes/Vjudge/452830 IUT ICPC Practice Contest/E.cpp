#include<bits/stdc++.h>
using namespace std;

void out(int x)
{
    for(int i = 1; i <= x; i++)
        cout << '(';
    for(int i = 1; i <= x; i++)
        cout << ')';
}

int main()
{
    int t, i, n, k, flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if(k == 2 || k == 4 || k == n)
        {
            cout << -1 << "\n";
            continue;
        }

        k = k/2;
        n = n/2;

        flag = 0;
        for(i = 1; i < k; i++)
        {
            if(n%(k-i) == i)
                continue;

            flag = 1;
            while(n >= k-i)
            {
                out(k-i);
                n -= (k-i);
            }
            out(n);
            cout << "\n";

        }

        if(!flag)
            cout << -1 << "\n";
    }
}
/*
3
4 2
8 6
10 6
*/
