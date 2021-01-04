#include<bits/stdc++.h>
using namespace std;

int team_no[1000009];

int main()
{
    int caseno = 0, team_cnt, i, j;
    string s;

    while(1)
    {
        cin >> team_cnt;
        if(!team_cnt)
            break;

        int team_size, id;

        for(i = 0; i < team_cnt; i++)
        {
            cin >> team_size;
            for(j = 0; j < team_size; j++)
            {
                cin >> id;
                team_no[id] = i;
            }
        }

        queue<int> q[team_cnt], teams;
        int team_id;

        cout << "Scenario #" << ++caseno << "\n";
        while(1)
        {
            cin >> s;
            if(s == "STOP")
                break;
            else if(s == "ENQUEUE")
            {
                cin >> id;
                team_id = team_no[id];

                if(q[team_id].empty())
                    teams.push(team_id);

                q[team_id].push(id);
            }

            else
            {
                team_id = teams.front();
                cout << q[team_id].front() << "\n";

                q[team_id].pop();

                if(q[team_id].empty())
                    teams.pop();
            }
        }

        cout << "\n";
    }
}
