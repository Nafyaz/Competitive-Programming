#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

set<pair<int, int>> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, q, d, x, y, minDiff, ansIdx;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> d;

        auto it = s.lower_bound({d, -1});
        if(it == s.end() || (*it).ff != d)
            s.insert({d, i});
    }

    cin >> q;

    while(q--)
    {
        cin >> x >> y;

        minDiff = y-x;
        ansIdx = 0;

        auto it = s.lower_bound({y-x, -1}); //lower_bound

        if(it == s.end())
        {
            it--;
            if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
            {
                minDiff = abs(y - (*it).ff - x);
                ansIdx = (*it).ss;
            }

            cout << ansIdx << "\n";
            continue;
        }

        if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
        {
            minDiff = abs(y - (*it).ff - x);
            ansIdx = (*it).ss;
        }

        if(it != s.begin()) //lower_bound-1
            it--;

        if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
        {
            minDiff = abs(y - (*it).ff - x);
            ansIdx = (*it).ss;
        }

        if(it != s.begin()) //lower_bound-2
            it--;

        if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
        {
            minDiff = abs(y - (*it).ff - x);
            ansIdx = (*it).ss;
        }

        it++; //lower_bound-1
        it++; //lower_bound
        it++; //lower_bound+1

        if(it == s.end())
        {
            cout << ansIdx << "\n";
            continue;
        }

        if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
        {
            minDiff = abs(y - (*it).ff - x);
            ansIdx = (*it).ss;
        }

        it++; //lower_bound+2

        if(it == s.end())
        {
            cout << ansIdx << "\n";
            continue;
        }

        if(y - (*it).ff > 0 && (minDiff > abs(y - (*it).ff - x) || (minDiff == abs(y - (*it).ff - x) && (*it).ss < ansIdx)))
        {
            minDiff = abs(y - (*it).ff - x);
            ansIdx = (*it).ss;
        }

        cout << ansIdx << "\n";
    }
}

