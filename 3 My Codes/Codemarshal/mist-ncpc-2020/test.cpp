#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> m;
    m.insert(3);
    m.insert(2);
    m.insert(7);
    m.insert(1);
    m.insert(9);
    m.insert(12);

    for(auto u : m)
        cout << u << " ";
    cout << endl;

    cout << *m.end() << endl;

    m.erase(*m.rbegin());

    for(auto u : m)
        cout << u << " ";
    cout << endl;
}
