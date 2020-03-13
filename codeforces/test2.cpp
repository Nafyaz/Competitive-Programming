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

bitset<10> b;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if((a.ff + a.ss -1)/a.ss != (b.ff + b.ss -1)/b.ss)
        return (a.ff + a.ss -1)/a.ss <= (b.ff + b.ss -1)/b.ss;
    return a.ff <= b.ff;
}

int main()
{
   ordered_set<double> s;
   s.insert(1);
   s.insert(4);
   s.insert(1);
   s.insert(69.5);
   s.insert(10);

   for(auto u : s)
        cout << u << " ";
   cout << endl;

    cout << *s.find_by_order(2) << endl;
    cout << s.order_of_key(100) << endl;

}
