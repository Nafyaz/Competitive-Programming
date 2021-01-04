#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, flag;
    string s, temp, table[10009][19];

    while(cin >> n >> m)
    {
        getline(cin, s);
        set<string> col[m];

        for(i = 0; i < n; i++)
        {
            getline(cin, s);

            temp = "";
            j = 0;
            for(auto u : s)
            {
                if(u == ",")
                {
                    col[j].insert(temp);
                    table[i][j] = temp;
                    j++;
                    temp = "";
                }
                else
                    temp = temp + u;
            }

            col[j].insert(temp);
            table[i][j] = temp;
        }

        flag = 1;
        for(i = 0; i < m; i++)
        {
            if(col[i].size() < n)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}
