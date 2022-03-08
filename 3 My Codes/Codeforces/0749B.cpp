#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x[3], y[3];

    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];

    cout << "3\n";
    cout << x[2] + x[1] - x[0] << " " << y[2] + y[1] - y[0] << "\n";
    cout << x[2] + x[0] - x[1] << " " << y[2] + y[0] - y[1] << "\n";
    cout << x[1] + x[0] - x[2] << " " << y[1] + y[0] - y[2] << "\n";
}
