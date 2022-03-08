#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a[4];

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    sort(a, a+4);

    if(a[0]+a[1] > a[2] || a[1]+a[2] > a[3])
        cout << "TRIANGLE";
    else if(a[0]+a[1] == a[2] || a[1]+a[2] == a[3])
        cout << "SEGMENT";
    else
        cout << "IMPOSSIBLE";
}
