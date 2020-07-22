#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i, x = 0, ans = 0;
    string s;
    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'B')
            x++;
        else
            ans += x;
    }

    cout << ans;
}
