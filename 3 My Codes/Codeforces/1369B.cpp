#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string s, pre, post;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        pre = post = "";
        for(i = 0; i < n && s[i] == '0'; i++)
            pre = pre + s[i];
        for(i = n-1; i >= 0 && s[i] == '1'; i--)
            post = s[i] + post;

        if(pre.size() + post.size() == n)
            cout << s << endl;
        else
            cout << pre + '0' + post << endl;
    }
}
