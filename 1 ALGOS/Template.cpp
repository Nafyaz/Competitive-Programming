/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

struct point
{
    ll x, y;

    point(ll _x=0, ll _y=0) {x=_x, y=_y;}

    point operator+(const point &p) {return {x+p.x, y+p.y};}
    point operator-(const point &p) {return {x-p.x, y-p.y};}
    ll operator^(const point &p) {return x*p.y - y*p.x;}
    bool operator<(const point &p) {return x<p.x || (x==p.x && y < p.y);}
    ll distSqr(const point &p) {return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
