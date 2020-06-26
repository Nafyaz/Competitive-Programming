#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, ans = 0;
    scanf("%d", &n);
    vector< pair <int, int> > v;
    vector< int > la[27], lb[27];

    string a, b;

    cin >> a >> b;

    for(i = 0; i < n; i++)
    {
        if(a[i] != '?')
            la[a[i] - 'a'].push_back(i+1);
        else
            la[26].push_back(i+1);
    }
    for(i = 0; i < n; i++)
    {
        if(b[i] != '?')
            lb[b[i] - 'a'].push_back(i+1);
        else
            lb[26].push_back(i+1);
    }


    for(i = 0; i < 26; i++)
    {
        ans += min(la[i].size(), lb[i].size());
        for(j = 0; j < min(la[i].size(), lb[i].size()); j++)
            v.push_back({la[i][j], lb[i][j]});
    }

//    cout << "lol";

    int qa = 0, qb = 0;
    for(i = 0; i < 26; i++)
    {
//        cout << "i" << i << endl;
//        cout << la[i].size() << " " << lb[i].size() << " ";
        for(j = min(la[i].size(), lb[i].size()); j < lb[i].size() && qa < la[26].size(); j++)
        {
//            cout << "j" << j << " ";

            v.push_back({la[26][qa], lb[i][j]});
            qa++;
        }
    }

//    cout << "lol";

    for(i = 0; i < 26; i++)
    {
        for(j = min(la[i].size(), lb[i].size()); j < la[i].size() && qb < lb[26].size(); j++)
        {
            v.push_back({la[i][j], lb[26][qb]});
            qb++;
        }
    }

//        cout << "lol";

    while(qa < la[26].size() && qb < lb[26].size())
    {
        v.push_back({la[26][qa], lb[26][qb]});
        qa++;
        qb++;
    }

    printf("%d\n", v.size());
    for(auto u : v)
        printf("%d %d\n", u.first, u.second);
}
