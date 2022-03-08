#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    double a, angle;

    cin >> n >> a;

    angle = (180 - 360.0/n) / (n-2);

    cout << "1 2 ";

    i = a / angle;

    if(i+1 > n-2)
        cout << 3;
    else if(i > 0 && abs(angle*i - a) < abs(angle*(i+1) - a))
        cout << n-i+1;
    else
        cout << n-i;
}
