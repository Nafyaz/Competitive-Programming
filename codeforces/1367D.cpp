#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int q, i, j, m, b[60];
    string s, t;
    cin >> q;
    while(q--)
    {
        cin >> s >> m;

        vector<int> v(26);
        for(auto u : s)
            v[u - 'a']++;

//        for(auto u : v)
//            cout << u << " ";
//        cout << endl;

        queue<int> q;
        for(i = 0; i < m; i++)
        {
           cin >> b[i];
           if(b[i] == 0)
            q.push(i);
        }

//        while(!q.empty())
//        {
//            cout << q.front() << endl;
//            q.pop();
//        }

        t = string(m, '*');
//        cout << t << endl;
        int done = 0;
        i = 25;
        while(done < m)
        {
            while(v[i] < q.size())
                i--;

//            cout << "i: " << i << endl;

            while(!q.empty())
            {
                int pos = q.front();
                q.pop();
                for(j = 0; j < m; j++)
                    b[j] -= abs(pos - j);
                b[pos] = -1;
                t[pos] = i + 'a';
                done++;
            }

            for(j = 0; j < m; j++)
            {
                if(b[j] == 0)
                    q.push(j);
            }

            i--;
        }

        cout << t << endl;
    }
}
