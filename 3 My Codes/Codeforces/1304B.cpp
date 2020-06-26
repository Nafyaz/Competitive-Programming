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

int main()
{
    int n, m, i;
    queue<string> left;
    stack<string> right;
    string s, t, mid = "";
    map<string, int> freq;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        freq[s]++;
    }

//    for(auto u : freq)
//        cout << u.ff << " " << u.ss << endl;

    for(auto u : freq)
    {
        s = u.ff;
        t = s;
        reverse(t.begin(), t.end());
        if((s == t && freq[s] > 1) || (s != t && freq[s] > 0 && freq[t] > 0))
        {
            left.push(s);
            right.push(t);
            freq[s]--;
            freq[t]--;
        }
        else if(s == t)
        {
            mid = s;
        }
    }

    string ans = "";
    while(!left.empty())
    {
        ans = ans + left.front();
        left.pop();
    }
    ans = ans + mid;
    while(!right.empty())
    {
        ans = ans + right.top();
        right.pop();
    }

    cout << ans.size() << endl << ans << endl;
}
