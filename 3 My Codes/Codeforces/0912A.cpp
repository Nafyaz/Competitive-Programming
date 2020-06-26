#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long yb, gb, bb;
    long long yc, bc;

    cin >> yc >> bc;
    cin >> yb >> gb >> bb;

    cout << max(0LL, 2*yb + gb - yc) + max(0LL, gb + 3*bb - bc);
}
