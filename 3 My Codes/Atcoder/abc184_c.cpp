#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    if(r1 == r2 && c1 == c2)
    {
        cout << 0;
        return 0;
    }

    if(r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r2 - r1) + abs(c2 - c1) <= 3)
    {
        cout << 1;
        return 0;
    }

    if((r1 + c1)%2 == (r2 + c2)%2 || abs(r2 - r1) + abs(c2 - c1) <= 6 || abs((r2+c2) - (r1+c1)) <= 3 || abs((r2-c2) -(r1-c1)) <= 3)
    {
        cout << 2;
        return 0;
    }

    cout << 3;
}
