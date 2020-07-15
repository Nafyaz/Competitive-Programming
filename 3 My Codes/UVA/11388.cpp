#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, g, l;
    cin >> t;
    while(t--)
    {
        cin >> g >> l;
        if(l % g != 0)
            cout << -1 << endl;
        else
            cout << g << " " << l << endl;
    }
}
