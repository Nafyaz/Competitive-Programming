#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, p, mods, ans = 0;
    map<int, int> freq;
    string s;

    cin >> s;

    reverse(s.begin(), s.end());

    p = 1;
    mods = 0;
    freq[0] = 1;
    for(i = 0; i < s.size(); i++)
    {
        mods = (mods + (s[i] - '0')*p) % 2019;
        ans += freq[mods];
        freq[mods]++;

        p = (p*10)%2019;
    }

    cout << ans;
}
