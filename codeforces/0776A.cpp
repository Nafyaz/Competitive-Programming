#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string a, b, x, y;

    cin >> a >> b;
    cout << a << " " << b << endl;

    cin >> n;

    while(n--)
    {
        cin >> x >> y;
        if(a == x)
            a = y;
        else
            b = y;
        cout << a << " " << b << endl;
    }
}
