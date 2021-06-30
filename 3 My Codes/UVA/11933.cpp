#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, a[2], x;

    while(cin >> n)
    {
        if(!n)
            break;

        a[0] = a[1] = 0;
        x = 0;

        for(i = 1; i <= n; i = i << 1)
        {
            if(n&i)
            {
                a[x] |= i;
                x = (x+1)%2;
            }
        }

        cout << a[0] << " " << a[1] << "\n";
    }
}
