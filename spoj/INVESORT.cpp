#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

unordered_map<ll, int> dis;

ll conv(string s)
{
    ll ret = 0;
    for(int i = 0; i < s.size(); i++)
        ret = ret*10 + s[i] - 'a';
    return ret;
}

void bfs(string s)
{
    queue<string> q;

    ll snum = conv(s);
    q.push(s);
    dis[snum] = 0;

    string p, temp;
    ll tempnum;
    int x;
    while(!q.empty())
    {
        p = q.front();
        x = dis[conv(p)];
        q.pop();
        for(int i = 0; i < p.size(); i++)
        {
            for(int j = i+1; j <= p.size(); j++)
            {
                temp = p;
                reverse(temp.begin() + i, temp.begin() + j);
                tempnum = conv(temp);
                if(dis.find(tempnum) != dis.end())
                    continue;

                dis[tempnum] = x+1;
                q.push(temp);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    bfs("abcdefghij");

    int i;
    map<char, char> mp;
    string s, t;
    while(1)
    {
        cin >> s >> t;
        if(s == "*" && t == "*")
            break;
        for(i = 0; i < s.size(); i++)
            mp[s[i]] = 'a' + i;
        s = "";
        for(i = 0; i < t.size(); i++)
            s = s+mp[t[i]];

        printf("%d\n", dis[conv(s)]);
    }
}
