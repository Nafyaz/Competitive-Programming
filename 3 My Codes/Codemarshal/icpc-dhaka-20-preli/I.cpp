#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    double i1, i2, b1, p, q, n, area;
    char c;

    while(1)
    {
        cin >> i1 >> i2 >> p >> c >> q;

        if(!i1 && !i2 && !p && !q)
            break;

        n = p/q;

        b1 = (n*n - n*n*i1 + i2 - 1) / (n*n/2 - n/2);

//        b1 = (2*p*p - 2*p*p*i1 + 2*q*q*i2 + q*q - p*q - 2*q*q) / (p*p - p*q);

        area = i1 + b1/2 - 1;

        cout << area*2 << "\n";
    }
}
