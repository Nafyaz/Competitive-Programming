#include<bits/stdc++.h>
using namespace std;

vector<int> bpos[1000009];
vector<int> apos;

int main()
{
    int i, j, n, a, c;
    cin >> n >> a;

    for(i = 0; i < n; i++)
    {
        cin >> c;
        bpos[c].push_back(i);
        if(c == a)
            apos.push_back(i);
    }

    int cnt, flag;
    for(i = 1; i < 1000000; i++)
    {
        if(bpos[i].size() < apos.size() || i == a)
            continue;
        flag = 1;
        for(j = 0; j < apos.size(); j++)
        {
            cnt = lower_bound(bpos[i].begin(), bpos[i].end(), apos[j]) - bpos[i].begin();
            if(cnt < j)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}
