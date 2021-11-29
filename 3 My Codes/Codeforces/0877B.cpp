#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, bcnt[5003], acnt[5003], ans = 0;
    string s;

    cin >> s;
    s = '#' + s + '#';

    bcnt[0] = 0;
    acnt[0] = 0;
    for(i = 1; i < s.size(); i++)
    {
        acnt[i] = acnt[i-1] + (s[i] == 'a');
        bcnt[i] = bcnt[i-1] + (s[i] == 'b');
    }

    for(i = 0; i < s.size(); i++)
    {
        for(j = i+1; j < s.size(); j++)
            ans = max(ans, acnt[i] + (bcnt[j-1] - bcnt[i]) + (acnt[s.size()-1]-acnt[j-1]));
    }

    cout << ans;
}
