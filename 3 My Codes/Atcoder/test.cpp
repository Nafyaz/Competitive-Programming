#include<bits/stdc++.h>
using namespace std;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
    int q, a[10] = {9, 9, 9, 6, 6, 4, 3, 1, -4, -4};

    while(1)
    {
        cin >> q;

        cout << upper_bound(a, a+10, q, greater<int>()) - a << "\n";
    }
}
