#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, x[1009], y[1009], area_2, b;

    while(cin >> n)
    {
        if(!n)
            break;

        area_2 = 0;
        b = n;
        for(i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];

            if(i)
            {
                area_2 += x[i-1]*y[i] - x[i]*y[i-1];
                b += __gcd(abs(x[i]-x[i-1]), abs(y[i]-y[i-1])) - 1;
            }
        }

        area_2 += x[n-1]*y[0] - x[0]*y[n-1];
        b += __gcd(abs(x[0]-x[n-1]), abs(y[0]-y[n-1])) - 1;

        area_2 = abs(area_2);

        cout << (area_2 - b + 2)/2 << "\n";
//        cout << b << "\n";
    }
}
