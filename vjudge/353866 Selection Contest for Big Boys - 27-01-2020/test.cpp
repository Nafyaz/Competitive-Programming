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
    bitset<10> left;
    left.set();
    cout << left << endl;
    left[0] = left[1] = left[2] = 0;
    cout << left << endl;
    cout << (left >> 2);

//    vector<int> v;
//    v.push_back(3, 4);
//    for(auto u : v)
//        cout << u << " ";

//    set<int> s;
//    s.insert(2);
//    s.insert(3);
//    s.insert(4);
//
//    if(s.find(3) == s.end())
//        cout << "lol";


}
