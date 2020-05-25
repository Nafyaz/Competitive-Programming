#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int cnt, pos1, pos2;
void cmp(string a, string b)
{
    cnt = 0, pos1 = 0, pos2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
        {
            cnt++;
            if(cnt == 1)
                pos1 = i;
            else
                pos2 = i;
        }
    }
}

int main()
{
    int t, i, j, k, n, m;
    string s[10];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        string x;
        set<string> st;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            st.insert(x);
        }

        n = st.size();
        i = 0;
        for(auto u : st)
            s[i++] = u;

        if(n == 1)
        {
            cout << s[0] << endl;
            continue;
        }

        string ans(n, '*');

        int flag = 1;
        for(i = 0; i < n && flag; i++)
        {
            for(j = 0; j < n && flag; j++)
            {
                cmp(s[i], s[j]);
                if(cnt > 2)
                {
                    flag = 0;
                    break;
                }

                else if(cnt == 2)
                {
                    for(k = 0; k < m; k++)
                    {
                        if(k != p.ss)
                        {
                            if(ans[k] == '*' || ans[k] == s[i][k])
                                ans[k] = s[i][k];
                            else
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }
                }

            }
        }

        if(!flag)
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 0; i < m; i++)
        {
            if(ans[i] != '*')
                cout << ans[i];
            else
                cout << 'a';
        }
        cout << endl;
    }
}
