/*
ID: nafis.f1
TASK: beads
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int func(int x)
{
    int i, fc, bc, f1, f2, b1, b2;

    f1 = 0;
    for(i = x%n; (!f1 || i != x) && (s[i] == 'b' || s[i] == 'w'); i = (i+1)%n)
        f1++;
    f2 = 0;
    for(i = x%n; (!f2 || i != x) && (s[i] == 'r' || s[i] == 'w'); i = (i+1)%n)
        f2++;
    fc = max(f1, f2);


    b1 = 0;
    for(i = (x-1+n)%n; (!b1 || i != (x-1+n)%n) && (s[i] == 'b' || s[i] == 'w'); i = (i-1+n)%n)
        b1++;
    b2 = 0;
    for(i = (x-1+n)%n; (!b2 || i != (x-1+n)%n) && (s[i] == 'r' || s[i] == 'w'); i = (i-1+n)%n)
        b2++;
    bc = max(b1, b2);

//    cout << x << ": " << f1 << " " << f2 << " " << b1 << " " << b2 << endl;
    if(fc + bc > n)
        return n;
    else
        return fc + bc;
}

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    cin >> n >> s;
    int i, ans = 0;
    for(i = 0; i < n; i++)
//        cout << i << ": " << func(i) << endl;
        ans = max(ans, func(i));

    cout << ans << endl;
}
