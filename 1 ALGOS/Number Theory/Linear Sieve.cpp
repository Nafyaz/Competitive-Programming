#include<bits/stdc++.h>
using namespace std;
#define N 10000009

int lp[N];
vector<int> pr;
void linsieve()
{
    int i, j;
    for(i = 2; i < N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for(j = 0; j < pr.size() && pr[j] <= lp[i] && i*pr[j] < N; j++)
            lp[i * pr[j]] = pr[j];
    }
}
