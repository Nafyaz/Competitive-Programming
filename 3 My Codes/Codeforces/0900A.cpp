#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, l = 0, r = 0, x, y;
    cin >> n;

    while(n--)
    {
        cin >> x >> y;
        if(x > 0)
            r++;
        else
            l++;
    }

    if(r <= 1 && l >= 1)
        cout << "Yes";
    else if(l <= 1 && r >= 1)
        cout << "Yes";
    else
        cout << "No";
}
