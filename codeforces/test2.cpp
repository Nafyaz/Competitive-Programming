#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld lond double
#define ff first
#define ss second

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.ss < b.ss;
}

int main()
{
    priority_queue<pair<int, int>, cmp> p;
    p.push({1, 2});
    p.push({4, 5});
    p.push({1, 1});
    p.push({12, 6});
    p.push({10, 21});
    p.push({21, 62});

    while(!p.empty())
    {
        cout << p.top().ff << "  " << p.top().ss << endl;
        p.pop();
    }
}
