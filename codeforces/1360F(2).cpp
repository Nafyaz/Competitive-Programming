#include<bits/stdc++.h>
using namespace std;

string s[10];
int n, cnt, pos1, pos2;
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

bool check(string x)
{
    for(int i = 0; i < n; i++)
    {
        cmp(x, s[i]);
        if(cnt > 1)
            return 0;
    }
    return 1;
}

int main()
{
    int t, i, j, k, m;
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

        if(check(s[0]))
        {
            cout << s[0] << endl;
            continue;
        }

        int p1, p2, flag = -1, prev = -1, previdx;
        for(i = 1; i < n && flag == -1; i++)
        {
            cmp(s[0], s[1]);
            p1 = pos1, p2 = pos2;
            if(cnt > 2)
            {
                flag = 0;
                break;
            }
            else if(cnt == 2)
            {
                x = s[0];
                x[p1] = s[i][p1];
                if(check(x))
                {
                    flag = 1;
                    break;
                }

                x = s[0];
                x[p2] = s[i][p2];
                if(check(x))
                {
                    flag = 1;
                    break;
                }

                flag = 0;
                break;
            }
            else
            {
                if(prev != -1 && prev != p1)
                {
                    x = s[0];
                    x[p1] = s[i][p1];
                    if(check(x))
                    {
                        flag = 1;
                        break;
                    }

                    x = s[0];
                    x[prev] = s[previdx][prev];
                    if(check(x))
                    {
                        flag = 1;
                        break;
                    }

                    flag = 0;
                    break;
                }
                else if(prev == -1)
                {
                    prev = p1;
                    previdx = i;
                }
            }
        }

        if(flag == 0)
            cout << -1 << endl;
        else
            cout << x << endl;
    }
}
