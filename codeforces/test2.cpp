#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> m;
    m.insert(1);
    m.insert(1);
    m.insert(1);
    m.insert(2);
    m.insert(3);
    m.insert(3);
    m.insert(3);

    for(auto u : m)
        cout << u << " ";
    cout << endl;
    m.erase(1);
    for(auto u : m)
        cout << u << " ";

}
