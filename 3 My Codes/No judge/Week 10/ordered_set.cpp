#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
//    set<int> S;
//
//    S.insert(15);
//    S.insert(7);
//    S.insert(10);
//    S.insert(7);

//    for(auto u : S)
//        cout << u << " ";
//    cout << "\n";

//    if(S.find(10) != S.end())
//        cout << "Found\n";
//    else
//        cout << "Not Found\n";

//    cout << (S.find(10) - S.begin());

//    S.erase(S.find(10), S.end());
//
//    for(auto u : S)
//        cout << u << " ";
//    cout << "\n";
//
//
    ordered_set<int> OS;

    OS.insert(15);
    OS.insert(7);
    OS.insert(10);
    OS.insert(7);

//    for(auto u : OS)
//        cout << u << " ";
//    cout << "\n";

//    cout << *(OS.find_by_order(1)) << "\n";
//
//    cout << OS.order_of_key(2) << "\n";
//    cout << OS.order_of_key(10) << "\n";
//    cout << OS.order_of_key(12) << "\n";
}
