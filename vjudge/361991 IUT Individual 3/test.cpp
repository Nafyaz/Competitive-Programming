#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fact(ll n)
{
    if(n <= 1)
        return 1;
    return n*fact(n-1);
}

void base(ll n, ll b)
{
    stack<char> s;
    while(n)
    {
        s.push(n%b + 'a');
        n /= b;
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main()
{
//    ll f = fact(10);
//    for(int i = 2; i <= 20; i++)
//    {
//        cout << i << ": ";
//        base(f, i);
//    }

    freopen("in.txt", "w", stdout);
    cout << 1000 << endl;
    for(int i = 1; i <= 1000; i++)
    {
        cout << i << endl;
    }
}
