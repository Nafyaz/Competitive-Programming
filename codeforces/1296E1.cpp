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
int n;
string s;
int color[209], prevpos[209];
void show()
{
    int i;
    cout << s << endl;
    for(i = 0; i < n; i++)
        cout << color[i] << " ";
    cout << endl;
}

int main()
{
    int i, j, key;
    cin >> n >> s;

    memset(color, -1, sizeof(color));
    for(i = 0; i < n; i++)
        prevpos[i] = i;

    for(i = 1; i < n; i++)
    {
        key = s[i];
        for(j = i-1; j >= 0 && s[j] > s[i]; j--)
        {
            show();
            if(color[prevpos[j]] != 1)
            {
                s[j+1] = s[j];
                prevpos[j+1] = prevpos[j];
                color[i] = 1;
                color[prevpos[j]] = 0;
            }
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for(i = 0; i < n; i++)
    {
        if(color[i] == -1)
            cout << 1;
        else
            cout << color[i];
    }
}
