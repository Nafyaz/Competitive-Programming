#include<bits/stdc++.h>
using namespace std;

int c[20], n, k;

vector<int> half1;

bool func(int i, int sum, int type)
{
    if(sum == k)
        return 1;
    if(sum > k)
        return 0;
    if(!type && i == n/2)
    {
        half1.push_back(sum);
        return 0;
    }
    if(type && i == n)
    {
        int rest = k - sum;
        int pos = lower_bound(half1.begin(), half1.end(), rest) - half1.begin();
        if(pos < half1.size() && half1[pos] == rest)
            return 1;
        else
            return 0;
    }

    if(func(i+1, sum, type) == 1)
        return 1;
    if(func(i+1, sum+c[i], type) == 1)
        return 1;
    if(func(i+1, sum+2*c[i], type) == 1)
        return 1;

    return 0;
}

int main()
{
    int t, caseno = 0, i;

    cin >> t;

    while(t--)
    {
        half1.clear();

        cin >> n >> k;

        for(i = 0; i < n; i++)
            cin >> c[i];

        cout << "Case " << ++caseno << ": ";
        if(func(0, 0, 0) == 1)
        {
            cout << "Yes\n";
            continue;
        }

        sort(half1.begin(), half1.end());

        if(func(n/2, 0, 1) == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
