#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y, w, a, b;

    cin >> y >> w;

    a = 6 - max(y, w) + 1;
    b = 6;

    cout << a/__gcd(a, b) << "/" << b/__gcd(a, b);
}
