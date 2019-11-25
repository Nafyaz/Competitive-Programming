#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x > 3)
            cout << "YES" << endl;
        else if(x != 1 && y <= 3)
            cout << "YES" << endl;
        else if(x == 1 && y == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
