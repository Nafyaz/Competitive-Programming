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

int main()
{
    int col[10] = {0, 0, 0,
                   1, 1, 1,
                   2, 2, 2,
                      3};

    int row[10] = {0, 1, 2,
                   0, 1, 2,
                   0, 1, 2,
                      1};

    int pos, i, n, minrow = 4, mincol = 4, maxrow = -1, maxcol = -1, digits[10] = {0};
    string s;
    cin >> n;
    cin >> s;

    for(i = 0; i < n; i++)
    {
        pos = (s[i] - '0' + 9)%10;
        digits[s[i] - '0'] = 1;

        minrow = min(minrow, row[pos]);
        maxrow = max(maxrow, row[pos]);

        mincol = min(mincol, col[pos]);
        maxcol = max(maxcol, col[pos]);
    }

    if(maxcol - mincol == 3)
        cout << "YES";
    else if(maxcol - mincol == 2 && maxrow - minrow == 2 && !digits[0] && (digits[7] || digits[9]))
        cout << "YES";
    else
        cout << "NO";
}
