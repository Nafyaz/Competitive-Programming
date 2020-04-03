//Credit goes to Anachor
#include <bits/stdc++.h>
using namespace std;

bool operator< (vector<int> &a, vector <int> &b)
{
    if (a.size()<b.size())
        return false;
    for (int i=0; i<b.size(); i++)
        if (a[i]>=b[i])
            return false;
    return true;
}

int main ()
{
    int N=1000000;
    ios::sync_with_stdio(false);
    int n, c;
    cin>>n>>c;
    vector<vector<int> > app(N+1);

    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        app[x].push_back(i);
    }

    for (int i=1; i<=N; i++)
        if (i!=c)
            if (app[i]<app[c])
            {
                cout<<i;
                return 0;
            }
    cout<<-1;
}
