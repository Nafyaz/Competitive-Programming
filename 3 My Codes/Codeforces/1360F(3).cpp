//Thanks to solaimanope
#include<bits/stdc++.h>
using namespace std;

int n, m;
string s[10];

bool check(string temp)
{
    int cnt;
    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] != temp[j])
                cnt++;
        }

        if(cnt > 1)
            return 0;
    }

    return 1;
}

int main()
{
    int t, i, j, c, flag;
    string temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < n; i++)
            cin >> s[i];

        flag = 0;
        for(i = 0; i < m && !flag; i++)
        {
            for(c = 'a'; c <= 'z' && !flag; c++)
            {
                temp = s[0];
                temp[i] = c;
                if(check(temp))
                    flag = 1;
            }
        }

        cout << (flag? temp : "-1") << endl;
    }
}
