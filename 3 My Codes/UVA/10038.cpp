#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, a_prev, mx, mn, diff;

    while(cin >> n)
    {
        set<int> s;
        mx = -1;
        mn = INT_MAX;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(i)
            {
                diff = abs(a - a_prev);
                s.insert(diff);
                mx = max(mx, diff);
                mn = min(mn, diff);
            }

            a_prev = a;
        }

        if(s.size() == n-1)
        {
            if(n == 1)
                cout << "Jolly\n";
            else if(mn == 1 && mx == n-1)
                cout << "Jolly\n";
            else
                cout << "Not jolly\n";
        }
        else
            cout << "Not jolly\n";
    }
}
