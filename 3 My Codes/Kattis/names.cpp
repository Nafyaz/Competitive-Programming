#include<bits/stdc++.h>
using namespace std;

int func(string s)
{
    int ret = 0;
    for(int i = 0; i < s.size()/2; i++)
        ret += (s[i] != s[s.size() - i - 1]);
    return ret;
}

int main()
{
    string s, p;
    cin >> s;
    int i, j, ans = s.size(), x;

    for(i = 0; i <= s.size(); i++)
    {
        p = s;
        x = i;
        for(j = i-1; j >= 0; j--)
            p = p + s[j];

        x += func(p);

//        cout << i << " " << p << " " << x << endl;
        ans = min(ans, x);
    }

    cout << ans;
}
