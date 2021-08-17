#include<bits/stdc++.h>
using namespace std;

bool cmp1(int a, int b)
{
    return a >= b;
}

bool cmp2(int a, int b)
{
    if(a%2 == 0 && b%2 == 1)
        return 0;
    else if(a%2 == 1 && b%2 == 0)
        return 1;

    return a <= b;
}

bool cmp3(pair<int, int> p, pair<int, int> q)
{
    if(p.first == q.first)
        return p.second <= q.second;
    return p.first <= q.first;
}

bool cmp4(pair<int, int> p, pair<int, int> q)
{
    if(p.second == q.second)
        return p.first <= q.first;
    return p.second <= q.second;
}

int main()
{
    int a[10] = {10, 7, 4, 1, 9, 6, 3, 8, 5, 2};

//    sort(a, a+10);
//    cout << "\nArray\n";
//    for(auto u : a)
//        cout << setw(3) << u << " ";
//    cout << "\n";

//    sort(a, a+10, cmp1);
//    for(auto u : a)
//        cout << setw(3) << u << " ";
//    cout << "\n";
//
//    sort(a, a+10, cmp2);
//    for(auto u : a)
//        cout << setw(3) << u << " ";
//    cout << "\n";
//
//    cout << "\nVector:\n";
    vector<int> v(a, a+10);
    for(auto u : v)
        cout << setw(3) << u << " ";
    cout << "\n";
//
//    sort(v.begin(), v.end(), cmp2);
//    for(auto u : v)
//        cout << setw(3) << u << " ";
//    cout << "\n";
//
//    vector<pair<int, int>> vp;
//    vp.push_back({9, 8});
//    vp.push_back({3, 2});
//    vp.push_back({5, 12});
//    vp.push_back({5, 4});
//    vp.push_back({11, 4});
//    vp.push_back({7, 6});
//
//    cout << "\nVector of Pairs\n";
//    for(auto u : vp)
//        cout << setw(3) << u.first << " " << setw(3) << u.second << "\n";
//
//    sort(vp.begin(), vp.end(), cmp3);
//    cout << "\nVector of Pairs sorted on first element\n";
//    for(auto u : vp)
//        cout << setw(3) << u.first << " " << setw(3) << u.second << "\n";
//
//    sort(vp.begin(), vp.end(), cmp4);
//    cout << "\nVector of Pairs sorted on second element\n";
//    for(auto u : vp)
//        cout << setw(3) << u.first << " " << setw(3) << u.second << "\n";
}
