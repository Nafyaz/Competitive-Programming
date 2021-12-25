#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, cnt, ans = 0;
    string s;

    cin >> n >> s;

    for(i = 0, cnt = 0; i < n; i++)
    {
        if(s[i] == 'x')
            cnt++;
        else
        {
            ans += max(0, cnt - 2);
            cnt = 0;
        }
    }

    ans += max(0, cnt - 2);

    cout << ans;
}
