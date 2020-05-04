#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, mx, mn;
    string s;
    cin >> n >> s;

    mx = mn = 0;

    for(i = 0; i < n; i++)
    {
        if(s[i] == 'L')
            mn--;
        else
            mx++;
    }
    cout << mx - mn + 1;
}
