#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n&1)
        {
            cout << 'a';
            n--;
        }

        x = (n/2) - 1;
        for(i = 1; i <= x; i++)
            cout << 'b';

        if(n)
            cout << 'c';

        for(i = 1; i <= x+1; i++)
            cout << 'b';

        cout << "\n";
    }
}
