#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, flag, ans;
    string A, B;

    cin >> t;

    while(t--)
    {
        cin >> n >> A >> B;

        set<int> s[20];

        flag = 1;
        for(i = 0; i < n; i++)
        {
            if(A[i] > B[i])
            {
                flag = 0;
                break;
            }
            else if(A[i] < B[i])
            {
                s[A[i] - 'a'].insert(B[i] - 'a');
            }
        }

        if(!flag)
        {
            cout << -1 << "\n";
            continue;
        }

        ans = 0;
        for(i = 0; i < 20; i++)
        {
            if(!s[i].empty() && i == (*s[i].begin()))
                s[i].erase(s[i].begin());

            if(s[i].empty())
                continue;

            s[*s[i].begin()].insert(s[i].begin(), s[i].end());
            ans++;
        }

        cout << ans << "\n";
    }
}
