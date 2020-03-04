#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

string s[100009];

int main()
{
    int n, i, j, mxlen = 0;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> s[i];
        mxlen = max(mxlen, (int)s[i].size());
    }

    sort(s, s+n);
    int low = 0, ch;
    for(i = 0; i < mxlen;)
    {
        ch = s[low][i];
        for(j = low + 1; j < n; j++)
        {
            if(s[j][i] != ch)
            {
                cout << "Impossible";
                return 0;
            }
        }

        i++;
        while(i >= s[low].size())
        {
            low++;
        }
    }

    cout << mxlen;
}

