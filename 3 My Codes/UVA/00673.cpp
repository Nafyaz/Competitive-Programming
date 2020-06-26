#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("out.txt", "w", stdout);
    stack<char> sk;
    int i, n;
    string s, ans;

    cin >> n;
    getline(cin, s);
    while(n--)
    {
        while(!sk.empty())
            sk.pop();
        ans = "Yes";
        getline(cin, s);
        for(i = 0; i < s.size(); i++)
        {
            if(sk.empty() && (s[i] == ')' || s[i] == ']'))
            {
                ans = "No";
                break;
            }
            if(!sk.empty() && sk.top() == '(' && s[i] == ']')
            {
                ans = "No";
                break;
            }
            if(!sk.empty() && sk.top() == '[' && s[i] == ')')
            {
                ans = "No";
                break;
            }
            if(!sk.empty() && sk.top() == '(' && s[i] == ')')
            {
                sk.pop();
                continue;
            }
            if(!sk.empty() && sk.top() == '[' && s[i] == ']')
            {
                sk.pop();
                continue;
            }

            sk.push(s[i]);
        }

        if(!sk.empty())
            ans = "No";

        cout << ans << endl;
    }
}
/*
3
([])
(([()])))
([()[]()])()
*/
