#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool nxtbrckt(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '<' && b == '>');
}

int main()
{
    int t, caseno = 0, i;

    cin >> t;
    string s;

    while(t--)
    {
        cin >> s;
        stack<pair<char, int>> st;
        int ans[100009] = {0};

        for(i = 0; i < s.size(); i++)
        {
            if(st.empty())
            {
                st.push({s[i], i});
                continue;
            }
            else if(nxtbrckt(st.top().ff, s[i]))
            {
                ans[st.top().ss] = i - st.top().ss + 1;
                st.pop();
            }
            else
                st.push({s[i], i});
        }

        for(i = s.size()-1; i >= 0; i--)
        {
            ans[i] += ans[i + ans[i]];
        }

        cout << "Case " << ++caseno << ":\n";
        for(i = 0; i < s.size(); i++)
            cout << ans[i] << "\n";

    }
}
