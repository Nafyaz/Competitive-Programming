#include<bits/stdc++.h>
using namespace std;

int trie[2500010][4];
int len[2500010], level[2500010];
int id = 0;

int main()
{
    int T, caseno = 0, n, i, j, r, x, l;
    string s;
    cin >> T;
    while(T--)
    {
        memset(trie, 0, sizeof(trie));
        memset(len, 0, sizeof(len));
        memset(level, 0, sizeof(level));
        id = 0;

        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> s;

            r = l = 0;

            for(j = 0; j < s.size(); j++)
            {
                switch(s[j])
                {
                case 'A':
                    x = 0;
                    break;
                case 'C':
                    x = 1;
                    break;
                case 'G':
                    x = 2;
                    break;
                case 'T':
                    x = 3;
                    break;
                }

                if(trie[r][x] == 0)
                    trie[r][x] = ++id;

                level[trie[r][x]] = level[r] + 1;
                r = trie[r][x];
                len[r]++;
            }
        }



//        for(i = 0; i < 20; i ++)
//        {
//            cout << i << " " << len[i] << " " << level[i] << endl;
//        }

        int mx = INT_MIN;
        for(i = 0; i < 2500010; i++)
            mx = max(mx, level[i] * len[i]);

        cout << "Case " << ++caseno << ": " << mx << endl;
    }
}
/*
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC
2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC
*/
