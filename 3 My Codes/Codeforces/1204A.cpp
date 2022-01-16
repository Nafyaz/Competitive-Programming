#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, oneCnt = 0, topOne = -1, ans;
    string s;

    cin >> s;

    if(s == "0")
    {
        cout << 0;
        return 0;
    }

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            oneCnt++;
            if(topOne == -1)
                topOne = i;
        }
    }

    ans = 0;
    for(i = s.size()-1; i >= 0; i -= 2)
    {
        if(i > topOne)
            ans++;
        if(i == topOne && oneCnt > 1)
            ans++;
    }

    cout << ans;
}

