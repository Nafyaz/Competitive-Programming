#include<bits/stdc++.h>
using namespace std;

int p[100009];

int Find(int u)
{
    if(u == p[u])
        return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v)
{
    int x = Find(u), y = Find(v);
    if(x == y)
        return;
    p[max(x, y)] = min(x, y);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t, i, n, u, v, ans1, ans2;
    string s, type;

    cin >> t;
    while(t--)
    {
        cin >> n;
        getline(cin, s);
//        cout << "~~" << s << "~~\n";

        ans1 = ans2 = 0;

        for(i = 0; i <= n; i++)
            p[i] = i;

        while(getline(cin, s))
        {
//            cout << "~~" << s << "~~\n";
            if(s == "")
                break;

            stringstream SS(s);

            SS >> type >> u >> v;


            if(type == "c")
                Union(u, v);
            else if(Find(u) == Find(v))
                ans1++;
            else
                ans2++;
        }

        cout << ans1 << "," << ans2 << "\n";

        if(t)
            cout << "\n";
    }
}
/*
2
10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

1
q 1 1
c 1 1
q 1 1
*/

