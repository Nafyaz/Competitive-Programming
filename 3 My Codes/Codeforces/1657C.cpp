#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isGood(char a, char b)
{
    if(a == '(' && b == '(')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == ')' && b == ')')
        return 1;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, op;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        op = 0;
        queue<ll> closing;

        for(i = 0; i < n; i++)
        {
            if(s[i] == ')')
                closing.push(i);
        }

        if(closing.empty())
        {
            cout << n/2 << " " << n%2 << "\n";
            continue;
        }

        for(i = 0; i+1 < n;)
        {
            if(isGood(s[i], s[i+1]))
            {
                i += 2;
                op++;
                continue;
            }

            while(!closing.empty() && i > closing.front())
                closing.pop();

            if(closing.size() == 1)
                break;

            op++;
            closing.pop();
            i = closing.front()+1;
        }

        cout << op << " " << n-i << "\n";
    }
}
