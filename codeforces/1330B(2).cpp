#include<bits/stdc++.h>
using namespace std;

int l[200009], posl[200009], posr[200009], checkl[200009], checkr[200009];

int main()
{
    int t, n, i, mx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> l[i];
            posl[i] = 0;
            posr[i] = 0;
            checkl[i] = checkr[i] = 0;
        }

        mx = -1;
        for(i = 0; i < n; i++)
        {
            if(checkl[l[i]])
                break;
            checkl[l[i]] = 1;
            mx = max(mx, l[i]);
            if(mx == i+1)
                posl[i] = 1;
        }

        mx = -1;
        queue<pair<int, int> > q;
        for(i = n-1; i >= 0; i--)
        {
            if(checkr[l[i]])
                break;
            checkr[l[i]] = 1;
            mx = max(mx, l[i]);
            if(mx == n-i)
            {
                posr[i] = 1;
                if(posl[i])
                    q.push({i, n-i});
            }
        }

        cout << q.size() << endl;
        while(!q.empty())
        {
            cout << q.front().first << " " << q.front().second << endl;
            q.pop();
        }
    }
}
