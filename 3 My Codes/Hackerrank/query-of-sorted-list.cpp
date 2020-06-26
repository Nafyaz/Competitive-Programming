#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, i, k, type;
    set<int> s;
    cin >> q;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> k;
            s.insert(k);
        }
        else if(s.size() < 2)
            cout << "Invalid Command\n";
        else
        {
            i = 0;
            for(auto u : s)
            {
                if(i&1)
                    cout << u << " ";
                i++;
            }
            cout << endl;
        }

    }
}
