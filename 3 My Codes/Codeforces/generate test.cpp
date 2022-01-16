#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "w", stdout);
    int T = 50, n = 6, x;
    cout << T << "\n";

    srand(time(0));
    while(T--)
    {
        cout << "Case:" << T << "\n";
        cout << n << "\n";
        set<int> s;
        x = 0;
        for(int i = 0; i < n; i++)
        {
            x = rand() % 20 + x + 1;

            while(s.find(x-10) != s.end())
                x = rand() % 20 + x + 1;

            cout << x << " " << rand()%2 << "\n";
        }
    }
}

