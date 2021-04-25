#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll b, r, bsum = 0, rsum = 0, i;

    for(i = 0; i < 5; i++)
    {
        cin >> b;
        bsum += b;
    }

    for(i = 0; i < 5; i++)
    {
        cin >> r;
        rsum += r;
    }

    cout << (bsum >= rsum? "Blue" : "Red");
}
