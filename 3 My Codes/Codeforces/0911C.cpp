#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ff first
#define ss second

int main()
{
    int a[3];

    cin >> a[0] >> a[1] >> a[2];


    sort(a, a+3);

//    for(auto u : a)
//        cout << u << " ";
    if(a[0] == 1)
        cout << "YES";
    else if(a[0] == 2 && a[1] == 2)
        cout << "YES";
    else if(a[0] == 2 && a[1] == 4 && a[2] == 4)
        cout << "YES";
    else if(a[0] == 3 && a[1] == 3 && a[2] == 3)
        cout << "YES";
    else
        cout << "NO";


}
