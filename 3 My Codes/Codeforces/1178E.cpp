#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n;
    string s, ans, rev;

    cin >> s;
    n = s.size();

    for(i = 0, j = n-1; ; i += 2, j -= 2)
    {
        if(i+1 < j-1)
        {
            if(s[i] == s[j] || s[i] == s[j-1])
                ans.push_back(s[i]);
            else if(s[i+1] == s[j] || s[i+1] == s[j-1])
                ans.push_back(s[i+1]);
        }

        if(i+2 >= j-2)
        {
            rev = ans;
            reverse(rev.begin(), rev.end());

            ans.push_back(s[(i+j)/2]);
            ans += rev;
            break;
        }
    }

    cout << ans;
}
