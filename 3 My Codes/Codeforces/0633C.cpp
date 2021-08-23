#include<bits/stdc++.h>
using namespace std;

int trie[1000006][26];
int last[1000006];
int id;
string s, w[100005];
deque<int> dq;

void Add(int idx)
{
    int i, r = 0, c;

    for(i = w[idx].size()-1; i >= 0; i--)
    {
        if(w[idx][i] >= 'A' && w[idx][i] <= 'Z')
            c = w[idx][i] - 'A';
        else
            c = w[idx][i] - 'a';

        if(trie[r][c] == 0)
            trie[r][c] = ++id;

        r = trie[r][c];
    }

    last[r] = idx;
}

bool decipher(int start)
{
    int i, r = 0, c;

    if(start == s.size())
        return 1;

    for(i = start; i < s.size(); i++)
    {
        c = s[i] - 'a';

        if(trie[r][c] == 0)
            return 0;

        r = trie[r][c];
        if(last[r])
        {
            dq.push_back(last[r]);

            if(decipher(i+1))
                return 1;
            else
                dq.pop_back();
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, i;

    cin >> n >> s;

    cin >> m;

    for(i = 1; i <= m; i++)
    {
        cin >> w[i];

        Add(i);
    }

    decipher(0);

    while(!dq.empty())
    {
        cout << w[dq.front()] << " ";
        dq.pop_front();
    }
}
/*
30
ariksihsidlihcdnaehsetahgnisol
10
Kira
hates
is
he
losing
death
childish
L
and
Note
*/
