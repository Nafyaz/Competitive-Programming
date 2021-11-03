#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, curr, pos[26], ans;
    string keyboard, s;

    cin >> T;

    while(T--)
    {
        cin >> keyboard >> s;

        for(i = 0; i < keyboard.size(); i++)
            pos[keyboard[i] - 'a'] = i;

        curr = pos[s[0] - 'a'];
        ans = 0;
        for(i = 1; i < s.size(); i++)
        {
            ans += abs(curr - pos[s[i] - 'a']);
            curr = pos[s[i] - 'a'];
        }

        cout << ans << "\n";
    }
}
