#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, flag = 1;
    cin >> n >> m;
    int l[m], a[n];

    memset(a, -1, sizeof(a));

    for(i = 0; i < m; i++)
    {
        cin >> l[i];
        l[i]--;

        if(flag && i)
        {
            if(a[l[i-1]] == -1)
                a[l[i-1]] = (l[i] - l[i-1] + n)%n;
            else if(a[l[i-1]] != (l[i] - l[i-1] + n)%n)
            {
                flag = 0;
            }
        }
    }

    int freq[n] = {0};

    for(i = 0; i < n; i++)
    {
        if(a[i] != -1)
        {
            freq[a[i]]++;
            if(freq[a[i]] > 1)
                flag = 0;
        }
    }

    i = 0, j = 0;
    while(i < n)
    {
        if(a[i] == -1)
        {
            while(j < n)
            {
                if(freq[j] == 0)
                {
                    a[i] = j;
                    freq[j] = 1;
                    break;
                }
                j++;
            }
        }
        i++;
    }

    if(!flag)
    {
        cout << -1;
        return 0;
    }

    for(i = 0; i < n; i++)
        cout << (a[i]? a[i] : n) << " ";
}

