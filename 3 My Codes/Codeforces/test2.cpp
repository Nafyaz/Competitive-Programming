#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &d) {
    d = gcd(abs(a), abs(b), x0, y0);
    if (c % d)
        return 0;

    x0 *= c / d;
    y0 *= c / d;
    x0 = (a < 0? -1 : 1) * x0;
    y0 = (b < 0? -1 : 1) * y0;
    return 1;
}

int main()
{
    cout << __gcd(1024, 15625);
}
