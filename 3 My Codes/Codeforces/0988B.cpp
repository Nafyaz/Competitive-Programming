#include<bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}

int main()
{
    int n, i, j, flag;
    string s[102];

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s+n, cmp);

    flag = 1;
    for(i = 1; i < n; i++)
    {
        if(s[i].find(s[i-1]) == string::npos)
        {
            flag = 0;
            break;
        }
    }

    if(!flag)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for(i = 0; i < n; i++)
        cout << s[i] << "\n";
}
