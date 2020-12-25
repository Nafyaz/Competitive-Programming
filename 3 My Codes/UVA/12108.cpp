#include<bits/stdc++.h>
using namespace std;

int n;
int pos[10], now[10], awake[10], cycle[10];

int func(int sleeping)
{
    int i, ret = 0;

    for(i = 0; i < n; i++)
    {
        pos[i]++;

        if(pos[i] <= awake[i])
            continue;

        else if(pos[i] == awake[i] + 1)
        {
            if(2 * sleeping > n)
                ret++;
            else
                pos[i] = 1;
        }

        else if(pos[i] <= cycle[i])
            ret++;

        else
            pos[i] = 1;
    }

    return ret;
}

int main()
{
    int caseno = 0, i, sleeping;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        sleeping = 0;
        for(i = 0; i < n; i++)
        {
            cin >> awake[i] >> cycle[i] >> pos[i];
            cycle[i] += awake[i];
            sleeping += (pos[i] > awake[i]? 1 : 0);
        }

        for(i = 1; i <= 500 && sleeping; i++)
            sleeping = func(sleeping);

        cout << "Case " << ++caseno << ": " << (i == 501? -1 : i) << "\n";
    }
}
