#include<bits/stdc++.h>
using namespace std;

struct contestant
{
    int team, penalty[10], solveCnt, solve_pen[10], total_pen;
};
bool func(contestant a, contestant b)
{
    if(a.solveCnt != b.solveCnt)
        return a.solveCnt > b.solveCnt;
    if(a.total_pen != b.total_pen)
        return a.total_pen < b.total_pen;
    return a.team < b.team;
}

int main()
{
    int t, i, id, pno, time;
    char verdict;
    string s;

    contestant c[109];

    cin >> t;
    getline(cin, s);
    getline(cin, s);

    while(t--)
    {
        memset(c, 0, sizeof c);

        while(getline(cin, s))
        {
            if(s == "")
                break;

            stringstream SS(s);
            SS >> id >> pno >> time >> verdict;
//            cout << id << " " << pno << " " << time << " " << verdict << "\n";

            c[id].team = id;

            if(c[id].solve_pen[pno] != 0)
                continue;

            if(verdict == 'C')
            {
                c[id].solveCnt++;
                c[id].solve_pen[pno] = c[id].penalty[pno] + time;
                c[id].total_pen += c[id].solve_pen[pno];
            }

            else if(verdict == 'I')
            {
                c[id].penalty[pno] += 20;
            }
        }

        sort(c, c+109, func);

        for(i = 0; c[i].team != 0; i++)
            cout << c[i].team << " " << c[i].solveCnt << " " << c[i].total_pen << "\n";

        cout << "\n";
    }
}
/*
1

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C
*/
