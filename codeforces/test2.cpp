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
   int i, j, a[6][6];

//   cout << (1) + (1 << 8) + (1 << 16) + (1 << 24);
   memset(a, 0xf, sizeof(a));

//   for(i = 0; i < 6; i++)
//    cout << a[0][i] << " ";

   for(int i = 0; i < 6; i++)
   {
       for(auto u : a[i])
        cout << u << " ";
       cout << endl;
   }
}
