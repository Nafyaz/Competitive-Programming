#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define pi acos(-1)

int main()
{
    int t;
    ld r1, r2, r3, k1, k2, k3, k4;
    cin >> t;
    while(t--)
    {
        cin >> r1 >> r2 >> r3;

        k1 = 1/r1;
        k2 = 1/r2;
        k3 = 1/r3;

        k4 = k1 + k2 + k3 + 2*sqrt(k1*k2 + k1*k3 + k2*k3);

        cout << fixed;
        cout << setprecision(8) << 1/k4 << endl;
    }
}

