/*
ID: nafis.f1
TASK: ride
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    string a, b;
    cin >> a >> b;

    int x = 1, y = 1;
    for(int i = 0; i < a.size(); i++)
        x = (x*(a[i] - 'A' + 1))%47;
    for(int i = 0; i < b.size(); i++)
        y = (y*(b[i] - 'A' + 1))%47;

    cout << (x==y? "GO" : "STAY") << endl;

}
