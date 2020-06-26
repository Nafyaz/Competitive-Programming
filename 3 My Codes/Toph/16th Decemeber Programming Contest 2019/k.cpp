#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int x, y, found = 0;
string grid[109];

void goL()
{
    while(grid[x][y-1] != '*')
    {
        if(grid[x][y] == 'O')
            found = 1;

        y--;
    }
}

void goR()
{
    while(grid[x][y+1] != '*')
    {
        if(grid[x][y] == 'O')
            found = 1;

        y++;
    }
}

void goT()
{
    while(grid[x-1][y] != '*')
    {
        if(grid[x][y] == 'O')
            found = 1;

        x--;
    }
}

void goB()
{
    while(grid[x+1][y] != '*')
    {
        if(grid[x][y] == 'O')
            found = 1;

        x++;
    }
}
int main()
{
    int i, j,r, c;
    char temp;
    cin >> r >> c >> temp;

    for(i = 0; i < r; i++)
    {
       getline(cin, grid[i]);
    }

    string s;
    cin >> x >> y >> s;
    x--;
    y--;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L')
            goL();
        if(s[i] == 'R')
            goR();
        if(s[i] == 'T')
            goT();
        if(s[i] == 'B')
            goB();
        if(grid[x][y] == 'O')
            found = 1;
    }

    cout << (found? "YES" : "NO");

}
