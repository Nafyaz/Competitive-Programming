#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x, y;
    scanf("%d", &n);
    deque <int> d;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        d.push_back(x);
    }
    string s;
    x = 0;

    while(!d.empty() && (x < d.front() || x < d.back()))
    {
        if(x < d.front() && x < d.back())
        {
            if(d.front() < d.back())
            {
                x = d.front();
                d.pop_front();
                s += 'L';
            }
            else
            {
                x = d.back();
                d.pop_back();
                s += 'R';
            }
        }
        else if(x < d.front())
        {
            x = d.front();
            d.pop_front();
            s += 'L';
        }
        else
        {
            x = d.back();
            d.pop_back();
            s += 'R';
        }
    }
    printf("%d\n", s.size());
    cout << s;
}
