#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, caseno = 0, x, a, i;
    queue<ll> q;
    cin >> t;

    while(t--)
    {
        cin >> x;
        a = x/9*10;
        for(i = a-10; i <= a+10; i++)
        {
            if(i - i/10 == x)
                q.push(i);
        }

        cout << "Case " << ++caseno << ": ";
        while(!q.empty())
        {
            cout << q.front();
            if(q.size() != 1)
                cout << " ";
            q.pop();
        }
        cout << endl;
    }
}
