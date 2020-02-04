#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    stack<int> s;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(!s.empty() && x*s.top() == -1)
            s.pop();
        else
            s.push(x);
    }
    cout << s.size();
}
