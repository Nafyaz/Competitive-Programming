#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {3, 7, 9, 20, 34, 34, 81, 99, 105, 111};

//    int pos1 = lower_bound(a, a+10, 34) - a; // Number of elements strictly less than 34
//    int pos2 = upper_bound(a, a+10, 34) - a; // Number of elements less than or equal 34
//
//    cout << pos1 << " " << pos2 << "\n";

    vector<int> v(a, a+10);

//    for(auto u : v)
//        cout << u << " ";
//    cout << "\n";

    int pos1 = lower_bound(v.begin(), v.end(), 34) - v.begin(); // Number of elements strictly less than 34
    int pos2 = upper_bound(v.begin(), v.end(), 34) - v.begin(); // Number of elements less than or equal 34

    cout << pos1 << " " << pos2 << "\n";
}
