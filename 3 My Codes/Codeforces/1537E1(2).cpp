#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;
    string s, t, ans;

    cin >> n >> k >> s;

    ans.push_back('z'+1);
    for(i = 1; i <= n; i++)
    {
        t = s.substr(0, i);

        while(t.size() < k)
            t = t + t;
        while(t.size() > k)
            t.pop_back();

        ans = min(ans, t);
    }

    cout << ans;
}
