#include<bits/stdc++.h>
using namespace std;

string s[1010];
int trie[1010][26];
int len[10100];
int id = 0, n;

int main()
{
    int T, i, j, caseno = 0;

    cin >> T;

    while(T--)
    {
        memset(trie, 0, sizeof(trie));
        memset(len, 0, sizeof(len));

        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];
            int r = 0;
            for(j = 0; j < s.size(); j++)
            {
                int x = str[i] - 'a';

                if(trie[r][x] == 0)
                    trie[r][x] = ++id;

                r = trie[r][x];
                len[r]++;
            }

        }
}
