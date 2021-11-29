#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y;

    cin >> t;

    while(t--)
    {
        cin >> x >> y;

        if((x+y) % 2 == 1)
            cout << "-1 -1\n";
        else if(x%2 == 1)
            cout << x/2 + 1 << " " << y/2 << "\n";
        else
            cout << x/2 << " " << y/2 << "\n";
    }
}
