#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

int woke[30];
vector<pii> edges;

int func()
{
    int wokeNeighbour[30] = {0}, ret = 0;
    queue<int> q;

    for(auto e : edges)
    {
        if(woke[e.ff] == 1 && woke[e.ss] == 0)
        {
            wokeNeighbour[e.ss]++;
            if(wokeNeighbour[e.ss] == 3)
            {
                q.push(e.ss);
                ret++;
            }
        }
        if(woke[e.ff] == 0 && woke[e.ss] == 1)
        {
            wokeNeighbour[e.ff]++;
            if(wokeNeighbour[e.ff] == 3)
            {
                q.push(e.ff);
                ret++;
            }
        }
    }

    while(!q.empty())
    {
        woke[q.front()] = 1;
        q.pop();
    }

    return ret;
}

int main()
{
    int N, M, years;
    string s, c;

    while(cin >> N)
    {
        memset(woke, 0, sizeof woke);
        edges.clear();

        cin >> M >> s;

        woke[s[0] - 'A'] = 1;
        woke[s[1] - 'A'] = 1;
        woke[s[2] - 'A'] = 1;

        while(M--)
        {
            cin >> s;

            edges.push_back({s[0] - 'A', s[1] - 'A'});
        }

        years = 0;

        while(1)
        {
            int temp = func();

            if(!temp)
                break;

            years ++;
        }

//        for(auto u : schar)
//            cout << u << " ";
//        cout << "\n";

//        for(auto u : edges)
//            cout << u.ff << " " << u.ss << "\n";

        int wokeCnt = 0;
        for(auto u : woke)
            wokeCnt += u;

        if(wokeCnt < N)
            cout << "THIS BRAIN NEVER WAKES UP\n";
        else
            cout << "WAKE UP IN, " << years << ", YEARS\n";

    }
}

