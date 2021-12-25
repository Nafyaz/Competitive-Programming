#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

double ans[31];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    ans[1] += 1;

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        if(p.ss == 30)
            continue;

    }
}

int main()
{
    int t, n;

    bfs(1, 1);

    for(n = 1; n <= 30; n++)
    {

    }

    cin >> t;

    while(t--)
    {
        cin >> n;


    }
}
