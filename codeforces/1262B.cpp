#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, q, p[100009], found, qprev;
    set <int> s;
    cin >> t;
    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            s.insert(i);

        found = 0;
        qprev = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> q;
            if(found)
                continue;
            if(q > qprev)
            {
                if(s.find(q) == s.end())
                {
                    found = 1;
                    continue;
                }
                p[i] = q;
                s.erase(s.find(q));
            }

            else
            {
                if(*s.begin() > q)
                {
                    found = 1;
                    continue;
                }
                p[i] = *s.begin();
                s.erase(s.begin());
            }

            qprev = q;
        }

        if(found)
            cout << -1 << endl;
        else
        {
            for(i = 1; i <= n; i++)
                cout << p[i] << " ";
            cout << endl;
        }
    }
}
