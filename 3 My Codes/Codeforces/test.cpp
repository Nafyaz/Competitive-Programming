#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 878, 23};
    int n = sizeof a / sizeof(int);

    sort(a, a+n, greater<int>());

    for(auto u : a)
        cout << u << " ";
}
