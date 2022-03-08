#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<string, vector<ll>> whoHaveThisSkill;

class Skill
{
public:
    string name;
    ll level;
};

class Contributor
{
public:
    string name;
    vector<skill> cSkills;
    ll skillSum;
};


class Project
{
public:
    string name;
    ll daysToComplete;
    ll score;
    ll best_before;
    vector<skill> pSkills;
    ll skillSum;
};

vector<Contributor> contributors(c);
vector<Project> projects(p);

bool possibleToComplete(ll i)
{
    for(auto s : projects[i].pSkills)
    {
        if(whoHaveThisSkill.find(s.name) != whoHaveThisSkill.end())
        for(auto j : whoHaveThisSkill[s.name])
        {
            if()
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll c, p, n, r, i, j;

    cin >> c >> p;


    for(i = 0; i < c; i++)
    {
        cin >> contributors[i].name >> n;
        contributors[i].cSkills.resize(n);
        for(auto &s : contributors[i].cSkills)
        {
            cin >> s.name >> s.level;
            s.skillSum += s.level;
        }
    }

    sort(contributors.begin(), contributors.end(), &[](Contributor c1, Contributor c2){return c1.skillSum < c2.skillSum});

    for(i = 0; i < c; i++)
    {
        for(auto s : contributors[i].cSkills)
            whoHaveThisSkill[s.name].push_back(i);
    }

    for(i = 0; i < p; i++)
    {
        flag = 1;
        cin >> projects[i].name >> projects[i].daysToComplete >> projects[i].score >> projects[i].best_before >> r;
        projects[i].pSkills.resize(r);
        for(auto &s : projects[i].pSkills)
        {
            cin >> s.name >> s.level;
            projects[i].skillSum += s.level;
        }
    }

    sort(projects.begin(), projects.end(), &[](Project p1, Project p2)
         {
             ll p1Heur = -p1.score*p1.score + p1.daysToComplete*p1.daysToComplete + p1.best_before*p1.best_before + p1.skillSum*p1.skillSum;
             ll p2Heur = -p2.score*p2.score + p2.daysToComplete*p2.daysToComplete + p2.best_before*p2.best_before + p2.skillSum*p2.skillSum;
             return p1Heur < p2Heur;
         });

    bool completedProjects[p] = {0};

    for(i = 0; i < p; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(!completedProjects[j] && possibleToComplete(j))
                complete(j);
        }
    }
}
