#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(4);
    v.push_back(20);
    v.push_back(-6);
    v.push_back(20);
    v.push_back(20);

    fill(v.begin()+1, v.begin() + 4, 5);

    v.clear();
    cout << v.size();

//    for(auto u : v)
//        cout << u << " ";
}
