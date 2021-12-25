#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int a[200005];
map<int, int> len;
stack<int> ans;

int main()
{
    int n, i, j, mxlen, mxidx;

    cin >> n;

    mxlen = 0;
    mxidx = -1;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        len[a[i]] = len[a[i]-1] + 1;

        if(len[a[i]] > mxlen)
        {
            mxlen = len[a[i]];
            mxidx = i;
        }
    }

    for(i = mxidx; i >= 0; i = j)
    {
        ans.push(i+1);
        for(j = i-1; j >= 0 && a[j] != a[i]-1; j--);
    }

    cout << ans.size() << "\n";
    while(!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}
