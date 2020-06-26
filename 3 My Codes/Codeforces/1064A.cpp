#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x+3);
    int a = x[0], b = x[1], c = x[2];

    cout << max(0, c - a - b + 1);
}
