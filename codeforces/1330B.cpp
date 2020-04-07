#include<bits/stdc++.h>
using namespace std;

int t, i, j, n, a[200009], posl[200009], posr[200009];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];
        set<int> left, right;

        int flag = 1, mx = 0;
        for(i = 0; i < n; i++)
        {
            if(!flag)
                posl[i] = 0;
            else if(left.find(a[i]) == left.end())
            {
                left.insert(a[i]);
                mx = max(mx, a[i]);
                if(left.size() == mx)
                    posl[i] = 1;
                else
                    posl[i] = 0;
            }
            else
            {
                flag = 0;
                posl[i] = 0;
            }
        }

        flag = 1, mx = 0;
        for(i = n-1; i >= 0; i--)
        {
            if(!flag)
                posr[i] = 0;
            else if(right.find(a[i]) == right.end())
            {
                right.insert(a[i]);
                mx = max(mx, a[i]);
                if(right.size() == mx)
                    posr[i] = 1;
                else
                    posr[i] = 0;
            }
            else
            {
                flag = 0;
                posr[i] = 0;
            }
        }

        queue<pair<int, int> > q;
        for(i = 0; i < n-1; i++)
        {
            if(posl[i] && posr[i+1])
                q.push({i+1, n-i-1});
        }

        cout << q.size() << endl;
        while(!q.empty())
        {
            cout << q.front().first << " " << q.front().second << endl;
            q.pop();
        }
    }
}
