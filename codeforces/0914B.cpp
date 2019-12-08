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
    int n, i, x, freq[100009] = {0};
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    for(i = 1; i < 100009; i++)
    {
        if(freq[i]&1)
        {
            cout << "Conan";
            return 0;
        }
    }

    cout << "Agasa";
}
