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
    int n, i, j, k, temp, col[200009] = {0};
    string s;
    cin >> n >> s;

    for(i = 1; i <= 26; i++)
    {
        temp = 0;
        for(j = 'a'; j <= 'z'; j++)
        {
            for(k = temp; k < n; k++)
            {
                if(!col[k] && j == s[k])
                {
                    col[k] = i;
                    temp = k+1;
                }

            }
        }
    }

    int mx = INT_MIN;
    for(i = 0; i < n; i++)
        mx = max(mx, col[i]);
    cout << mx << endl;
    for(i = 0; i < n; i++)
        cout << col[i] << " ";
}
