#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p, c, i, x, caseno = 0;
    char type;
    while(cin >> p >> c)
    {
        if(!p && !c)
            break;
        cout << "Case "<< ++caseno << ":" << endl;
        queue<int> q, temp;
        for(i = 1; i <= min(p, 10000); i++)
            q.push(i);
        while(c--)
        {
            cin >> type;
            if(type == 'E')
            {
                cin >> x;
                while(!q.empty())
                {
                    if(q.front() != x)
                        temp.push(q.front());
                    q.pop();
                }
                q.push(x);
                while(!temp.empty())
                {
                    q.push(temp.front());
                    temp.pop();
                }
            }
            else
            {
                cout << q.front() << endl;
                q.push(q.front());
                q.pop();
            }
        }
    }
}
