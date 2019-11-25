#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, j;
    cin >> t;

    char temp;
    queue <char> o, e;
    string n;

    while(t--)
    {
        while(!o.empty())
            o.pop();
        while(!e.empty())
            e.pop();

        cin >> n;
        for(auto u : n)
        {
            if((u - '0')%2 == 0)
                e.push(u);
            else
                o.push(u);
        }

        while(!o.empty() || !e.empty())
        {
            if(o.empty())
            {
                cout << e.front();
                e.pop();
            }
            else if(e.empty())
            {
                cout << o.front();
                o.pop();
            }
            else
            {
                temp = min(o.front(), e.front());
                cout << temp;
                if(temp == o.front())
                    o.pop();
                else
                    e.pop();
            }
        }

        cout << endl;

    }
}
