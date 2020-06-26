//I cannot prove it, but lets try
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define ff first
#define ss second

int main()
{
    int i, j, left[1009], right[1009], cnt;

    string s;
    cin >> s;

    cnt = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            left[i] = ++cnt;
        else
            left[i] = cnt;
    }

    cnt = 0;
    for(i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == ')')
            right[i] = ++cnt;
        else
            right[i] = cnt;
    }

    int mx = 0, mxidx = -1;

    for(i = 0; i < s.size(); i++)
    {
        if(mx < min(left[i], right[i]))
        {
            mx = min(left[i], right[i]);
            mxidx = i;
        }
    }

    set<int> st;
    for(i = 0; i <= mxidx; i++)
    {
        if(s[i] == '(')
            st.insert(i+1);
    }
    for(i = s.size() - 1; i > mxidx; i--)
    {
        if(s[i] == ')' && mx >= right[i])
            st.insert(i+1);
    }

    cout << (st.size()? 1 : 0) << endl;
    if(st.size())
        cout << st.size() << endl;
    for(auto u : st)
        cout << u << " ";
    cout << endl;
}
