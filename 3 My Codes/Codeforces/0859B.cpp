#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;

    cin >> n;
    l = sqrt(n);

    cout << l*2 + (n+l-1)/l*2;
}
