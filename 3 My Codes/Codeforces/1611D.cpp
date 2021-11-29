#include<bits/stdc++.h>
using namespace std;

int b[200005];
int p[200005], pos[200005];
int dis[200005];
int disFromRoot[200005];

int main()
{
    int T, n, i, root, flag, total;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> b[i];

            if(i == b[i])
                root = i;
        }

        for(i = 1; i <= n; i++)
        {
            cin >> p[i];
            pos[p[i]] = i;
        }

        if(p[1] != root)
        {
            cout << "-1\n";
            continue;
        }

        flag = 1;
        for(i = 1; i <= n && flag; i++)
        {
            if(i != root && pos[b[i]] > pos[i])
                flag = 0;
        }

        if(!flag)
        {
            cout << "-1\n";
            continue;
        }

        dis[p[1]] = 0;
        disFromRoot[p[1]] = 0;
        total = 0;
        for(i = 2; i <= n; i++)
        {
            total++;
            dis[p[i]] = total - disFromRoot[b[p[i]]];
            disFromRoot[p[i]] = total;
        }

        for(i = 1; i <= n; i++)
            cout << dis[i] << " ";
        cout << "\n";
    }
}
