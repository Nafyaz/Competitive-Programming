#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    pair<string, vector<int>> p[5];

    p[0] = {1, 2};
    p[1] = {1, 2};
    p[2] = {1, 2};
    p[3] = {1, 2};
    p[4] = {1, 2};

//    for(auto u : p)
//        cout << u.ff << " " << u.ss << "\n";

    for(int i = 0; i < 5; i++)
        cout << p[i].ff << " " << p[i].ss << "\n";
}
