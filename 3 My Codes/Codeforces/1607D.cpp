#include<bits/stdc++.h>
using namespace std;

int a[200005];
bool fix[200005];

int main()
{
    int T, i, j, n, flag;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            fix[i+1] = 0;
        }
        cin >> s;

        vector<int> blue, red;
        flag = 1;
        for(i = 0; i < n && flag; i++)
        {
            if(a[i] > n && s[i] == 'B')
                a[i] = n;
            else if(a[i] > n)
                flag = 0;
            if(a[i] < 1 && s[i] == 'R')
                a[i] = 1;
            else if(a[i] < 1)
                flag = 0;

            if(s[i] == 'B')
                blue.push_back(a[i]);
            else
                red.push_back(a[i]);
        }
        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        sort(red.begin(), red.end(), greater<int>());
        for(i = 0, j = n; i < red.size() && flag; i++, j--)
        {
            if(red[i] <= j)
                fix[j] = 1;
            else
                flag = 0;
        }
        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        sort(blue.begin(), blue.end());
        for(i = 0, j = 1; i < blue.size() && flag; i++, j++)
        {
            if(blue[i] >= j)
                fix[j] = 1;
            else
                flag = 0;
        }
        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
