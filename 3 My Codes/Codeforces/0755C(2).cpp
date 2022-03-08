//Follow mohammedehab2002
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, p, cnt = 0;
    set<int> s;

    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> p;

        if(p == i)
            cnt++;
        else
            s.insert(p);
    }

    cout << cnt + s.size()/2;
}
