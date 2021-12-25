#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, caseno = 0, n, runs, outs;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n;

        runs = 0;
        outs = n;

        while(n--)
        {
            cin >> s;

            if(s.back() == '*')
            {
                outs--;
                runs += stoi(s.substr(0, (int)s.size()-1));
            }
            else
                runs += stoi(s);
        }

        if(outs)
            cout << "Case " << ++caseno << ": " << runs/outs << "\n";
        else
            cout << "Case " << ++caseno << ": -1\n";
    }
}
