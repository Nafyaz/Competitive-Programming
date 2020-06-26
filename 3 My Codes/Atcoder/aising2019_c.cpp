#include<bits/stdc++.h>
using namespace std;
#define ll long long

string grid[409];
ll h, w, vis[409][409], black, white;
void func1(ll i, ll j);
void func2(ll i, ll j);

void func2(ll i, ll j)
{
    if(i >= h || i < 0 || j >= w || j < 0 || grid[i][j] != '.' || vis[i][j])
        return;

    white++;
    vis[i][j] = 1;

    if(!vis[i+1][j])
        func1(i+1, j);
    if(!vis[i-1][j])
        func1(i-1, j);
    if(!vis[i][j+1])
        func1(i, j+1);
    if(!vis[i][j-1])
        func1(i, j-1);
}

void func1(ll i, ll j)
{
    if(i >= h || i < 0 || j >= w || j < 0 || grid[i][j] != '#' || vis[i][j])
        return;

    black++;
    vis[i][j] = 1;

    if(!vis[i+1][j])
        func2(i+1, j);
    if(!vis[i-1][j])
        func2(i-1, j);
    if(!vis[i][j+1])
        func2(i, j+1);
    if(!vis[i][j-1])
        func2(i, j-1);

}

int main()
{
    ll i, j, ans = 0;
    scanf("%lld %lld", &h, &w);
    for(i = 0; i < h; i++)
        cin >> grid[i];

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(grid[i][j] == '#' && !vis[i][j])
            {
                black = 0;
                white = 0;
                func1(i, j);
                ans += black*white;
            }
        }
    }

    printf("%lld", ans);
}

