#include<bits/stdc++.h>
using namespace std;

int trie[100010][11];
int len[100010], last[100010];
int id = 0;

int main()
{
    int T, caseno = 0, i, j, n, flag;
    cin >> T;
    while(T--)
    {
        memset(trie, 0, sizeof(trie));
        memset(len, 0, sizeof(len));
        memset(last, 0, sizeof(last));
        id = flag = 0;

        string s[10010];
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> s[i];

        sort(s, s+n);

        for(i = 0; i < n; i++)
        {
            int r = 0;
            for(j = 0; j < s[i].size(); j++)
            {
                int x = s[i][j] - '0';

                if(trie[r][x] == 0)
                    trie[r][x] = ++id;

                r = trie[r][x];
                if(last[r])
                    flag = 1;

                len[r]++;
            }
            last[r] = 1;
        }

        cout << "Case " << ++caseno << ":" << " ";

        flag ? cout << "NO" : cout << "YES";
        cout << endl;
    }
}
