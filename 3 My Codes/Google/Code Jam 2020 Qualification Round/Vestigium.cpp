#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, m[109][109], i, j, trace, r, c, mx;
    set<int> s;
    cin >> t;
    while(t--)
    {
        r = c = trace = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            s.clear();
//            mx = 0;
            for(j = 0; j < n; j++)
            {
                cin >> m[i][j];
                if(i == j)
                    trace += m[i][j];
                s.insert(m[i][j]);
//                mx = max(mx, m[i][j]);
            }
            if(s.size() < n)
                r++;
        }

        for(j = 0; j < n; j++)
        {
            s.clear();
            for(i = 0; i < n; i++)
            {
                s.insert(m[i][j]);
            }
            if(s.size() < n)
                c++;
        }

        cout << "Case #" << ++caseno << ": " << trace << " " << r << " " << c << endl;
    }
}
