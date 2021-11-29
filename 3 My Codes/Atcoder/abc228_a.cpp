#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, t, x;

    cin >> s >> t >> x;

    if(s < t)
    {
        if(s <= x && x < t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if(s <= x || x < t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
