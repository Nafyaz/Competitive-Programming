#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cout << setw(10) << "init: " << a << "\n";

    memset(&a, 0, sizeof a);
    cout << setw(10) << "0: " << a << "\n";

    memset(&a, -1, sizeof a);
    cout << setw(10) << "-1: " << a << "\n";

    memset(&a, 1, sizeof a);
    cout << setw(10) << "1: " << a << "\n";

    memset(&a, 256, sizeof a);
    cout << setw(10) << "256: " << a << "\n";
//
    int b[10];
    memset(b, 0, sizeof b);
    cout << setw(10) << "0:\n";
    for(auto u : b)
        cout << u << " ";
    cout << "\n";

    memset(b, -1, sizeof b);
    cout << setw(10) << "-1:\n";
    for(auto u : b)
        cout << u << " ";
    cout << "\n";

    memset(b, 1, sizeof b);
    cout << setw(10) << "1:\n";
    for(auto u : b)
        cout << u << " ";
    cout << "\n";

    memset(b, 255, sizeof b);
    cout << setw(10) << "255:\n";
    for(auto u : b)
        cout << u << " ";
    cout << "\n";
}
