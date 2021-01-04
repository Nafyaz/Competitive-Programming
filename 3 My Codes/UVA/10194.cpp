#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

class teams
{
public:

    ll p, wins, lose, goalsc, goalag, played;
    string name;

    teams()
    {
        p = wins = lose = goalsc = goalag = played = 0;
    }
};

bool cmp(teams a, teams b)
{
    if(a.p != b.p)
        return a.p > b.p;
    if(a.wins != b.wins)
        return a.wins > b.wins;
    if(a.goalsc - a.goalag != b.goalsc - b.goalag)
        return a.goalsc - a.goalag > b.goalsc - b.goalag;
    if(a.goalsc != b.goalsc)
        return a.goalsc > b.goalsc;
    if(a.played != b.played)
        return a.played < b.played;

    char x, y;
    for(int i = 0; i < a.name.size() && i < b.name.size(); i++)
    {
        x = tolower(a.name[i]);
        y = tolower(b.name[i]);

        if(x != y)
            return x < y;
    }

    return a.name.size() < b.name.size();
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ll t, teamno, i, j, G, u, ugoal, v, vgoal, cnt = 0;
    string trname, teamname, game, temp;
    map<string, ll> mp;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        cnt++;
        if(cnt != 1)
            cout << endl;
        getline(cin, trname);
        cin >> teamno;
        cin.ignore();
        teams obj[teamno+1];
        for(i = 1; i <= teamno; i++)
        {
            getline(cin, teamname);
            mp[teamname] = i;
            obj[i].name = teamname;
//            cout << teamname << ": " << mp[teamname] << endl;
        }
        cin >> G;
        cin.ignore();
        while(G--)
        {
            getline(cin, game);
            temp = "";
            for(i = 0; game[i] != '#'; i++)
                temp += game[i];
            u = mp[temp];

            temp = "";
            for(i = i+1; game[i] != '@'; i++)
                temp += game[i];

            ugoal = stoi(temp);

            temp = "";
            for(i = i+1; game[i] != '#'; i++)
                temp += game[i];
            vgoal = stoi(temp);

            temp = "";
            for(i = i+1; i < game.size(); i++)
                temp += game[i];
            v = mp[temp];

//            cout << u << " " << ugoal << " " << v << " " << vgoal << endl;

            obj[u].goalsc += ugoal;
            obj[v].goalag += ugoal;
            obj[v].goalsc += vgoal;
            obj[u].goalag += vgoal;

            obj[u].played++;
            obj[v].played++;

            if(ugoal > vgoal)
            {
                obj[u].wins++;
                obj[v].lose++;

                obj[u].p += 3;
            }
            else if(ugoal < vgoal)
            {
                obj[u].lose++;
                obj[v].wins++;

                obj[v].p += 3;
            }
            else
            {
                obj[u].p++;
                obj[v].p++;
            }
        }

        sort(obj+1, obj+teamno+1, cmp);

        cout << trname << endl;

        for(i = 1; i <= teamno; i++)
        {
            cout << i << ") " << obj[i].name << " " << obj[i].p << "p, ";
            cout << obj[i].played << "g (" << obj[i].wins << "-" << obj[i].played - obj[i].wins - obj[i].lose << "-" << obj[i].lose << "), ";
            cout << obj[i].goalsc - obj[i].goalag << "gd (" << obj[i].goalsc << "-" << obj[i].goalag << ")" << endl;
        }
//        cout << endl;
    }
}

/*
2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D
*/
