#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p, l, r, mx, mn;

    cin >> l >> r >> p;

    mx = max(l, r);
    mn = min(l, r);

    if(100*mn >= mx * p)
        cout << "Ambidextrous";
    else if(l == mx)
        cout << "Left-handed";
    else
        cout << "Right-handed";
}
