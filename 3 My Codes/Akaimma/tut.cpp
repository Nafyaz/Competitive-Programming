#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> d;
    d.push_back(9);
    d.push_back(7);
    d.insert(d.begin()+1, 10, 1);
    d.erase(d.begin()+5, d.end());
    d.clear();


    int x[5] = {1, 2, 3, 4, 5};
    for(auto u : x)
        printf("%d ", u);
}
