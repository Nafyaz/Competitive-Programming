#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<long long> s;
    long long x;

    while(cin >> x)
        s.push(x);

    while(!s.empty())
    {
        cout << fixed << setprecision(4) << sqrt(s.top()) << "\n";
        s.pop();
    }
}
