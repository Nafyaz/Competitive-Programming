#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "w", stdout);

    int t = 100;
    cout << t << "\n";

    for(int i = 0; i < t; i++)
    {
        int sz = rand()%100;
        while(sz--)
        {
            int x = rand()%3;

            if(x)
                cout << '^' ;
            else
                cout << '_';
        }
        cout << "\n";
    }
}
