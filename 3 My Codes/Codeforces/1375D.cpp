#include<bits/stdc++.h>
using namespace std;

int mex(vector<int> a)
{
    int i;
    map<int, int> mp;
    for(i = 0; i < a.size(); i++)
        mp[a[i]]++;

    for(i = 0; i <= a.size(); i++)
    {
        if(mp[i] == 0)
            return i;
    }
}

int main()
{
    int t, n, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> ans, a(n);
        queue<int> q;
        for(i = 0; i < n; i++)
            cin >> a[i];

        for(i = 0; i < n; i++)
        {

            if(is_sorted(a.begin(), a.end()))
                break;

            for(j = 0; j < n; j++)
            {
                if(a[j] == i)
                    q.push(j);
            }

            while(!q.empty())
            {
                int m = mex(a);
                a[q.front()] = m;
                ans.push_back(q.front() + 1);
                q.pop();
            }

            ans.push_back(i+1);
            a[i] = i;
        }

        cout << ans.size() << endl;
        for(auto u : ans)
            cout << u << " ";
        cout << endl;
        for(i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
