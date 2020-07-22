#include<bits/stdc++.h>
using namespace std;

string func(string s, int last)
{
    int i;
    string ret;
    for(i = 0; i <= last; i++)
        ret = ret + (s[i] == '0'? '1' : '0');
    reverse(ret.begin(), ret.end());
    for(i = last + 1; i < s.size(); i++)
        ret = ret + s[i];
    return ret;
}

int main()
{
    int t, n, i, last;
    string a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        vector<int> ans;
        last = n-1;
        while(a != b && last >= 0)
        {
//            cout << a << " " << b << endl;
            if(a[last] == b[last])
            {
                last--;
                continue;
            }
            if(a[0] == b[last])
            {
                ans.push_back(0);
                a[0] = (b[last] == '0'? '1' : '0');
            }

            ans.push_back(last);
            a = func(a, last);
        }

        cout << ans.size() << " ";
        for(i = 0; i < ans.size(); i++)
            cout << ans[i] + 1<< " ";
        cout << "\n";
    }
}
