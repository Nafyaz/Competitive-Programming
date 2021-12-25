#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(11);
    s.insert(15);
    s.insert(4);

    s.erase(s.begin());

    cout << *(s.begin());
}
