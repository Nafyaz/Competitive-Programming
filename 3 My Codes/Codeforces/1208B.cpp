#include<bits/stdc++.h>
using namespace std;

int n;
int a[2003];
map<int, int> freq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    ans = 0;
    for(i = 0; i < n; i++)
    {
        if(freq.find(a[i]) == freq.end())
        {
            freq[a[i]] = 1;
            j = i;
            ans = max(ans, i+1);
        }
        else
            break;
    }

    for(i = n-1; i >= 0; i--)
    {
        while(freq[a[i]] != 0 && j >= 0)
        {
            freq[a[j]]--;
            j--;
        }

        if(freq[a[i]] == 0)
        {
            freq[a[i]]++;
            ans = max(ans, j+1+n-i);
        }
        else
            break;
    }

    cout << n - ans;
}
