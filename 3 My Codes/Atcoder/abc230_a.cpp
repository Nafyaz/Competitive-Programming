#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cin >> N;

    if(N < 42)
        cout << "AGC0" << setfill('0') << setw(2) << N;
    else
        cout << "AGC0" << N+1;
}
