#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i, ans = 0;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if((s[i] - '0') % 4 == 0)
            ans++;
        if(i > 0 && ((s[i-1] - '0')*10 + (s[i] - '0')) % 4 == 0)
            ans += i;
    }

    cout << ans;
}
