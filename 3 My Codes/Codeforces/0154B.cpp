#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool on[100005];
ll primesPresent[100005];

ll Add(ll id)
{
    ll i, cnt, n = id;
    queue<ll> q;

    for(i = 2; i < 100005 && i*i <= n; i++)
    {
        for(cnt = 0; n%i == 0; cnt++)
            n /= i;

        if(cnt)
        {
            if(primesPresent[i])
                return primesPresent[i];

            q.push(i);
        }
    }

    if(n > 1)
    {
        if(primesPresent[n])
            return primesPresent[n];
        q.push(n);
    }

    on[id] = 1;
    while(!q.empty())
    {
        primesPresent[q.front()] = id;
        q.pop();
    }

    return 0;
}

void Sub(ll id)
{
    ll i, cnt, n = id;
    for(i = 2; i < 100005 && i*i <= n; i++)
    {
        for(cnt = 0; n%i == 0; cnt++)
            n /= i;

        if(cnt)
            primesPresent[i] = 0;
    }

    if(n > 1)
        primesPresent[n] = 0;

    on[id] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, conflict;
    string c;

    cin >> n >> m;

    while(m--)
    {
        cin >> c >> i;

        if(c == "+")
        {
            if(on[i])
                cout << "Already on\n";
            else
            {
                conflict = Add(i);

                if(conflict)
                    cout << "Conflict with " << conflict << "\n";
                else
                    cout << "Success\n";
            }
        }
        else if(c == "-")
        {
            if(on[i])
            {
                Sub(i);
                cout << "Success\n";
            }
            else
                cout << "Already off\n";
        }
    }
}
