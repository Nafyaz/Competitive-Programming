#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x, y, z;

    cin >> n;

    vector<int> a(n);

    cout << "? 2 3\n";
    cin >> x;
    cout << "? 1 3\n";
    cin >> y;
    cout << "? 1 2\n";
    cin >> z;

    a[0] = (x+y+z)/2 - x;
    a[1] = (x+y+z)/2 - y;
    a[2] = (x+y+z)/2 - z;

    for(i = 3; i < n; i++)
    {
        cout << "? " << i << " " << i+1 << "\n";
        cin >> x;

        a[i] = x - a[i-1];
    }

    cout << "! ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
