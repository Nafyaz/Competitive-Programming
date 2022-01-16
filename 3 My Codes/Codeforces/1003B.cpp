#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, a[2], x, last;

    cin >> a[0] >> a[1] >> x;

    string s;

    if(a[0] > a[1])
        last = 0;
    else
        last = 1;

    while(x >= 0)
    {
        s.push_back('0'+last);
        a[last] --;
        last ^= 1;
        x--;
    }

    s = s[0] + string(a[s[1] - '0'], s[1]) + s.substr(1);
    s = string(a[s[0] - '0'], s[0]) + s;

    cout << s;
}
