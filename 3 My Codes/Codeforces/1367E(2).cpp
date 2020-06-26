#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int k;
bool check(int m)
{
    int g = __gcd(m, k);
    int t = m / g;

    for(int i = 0; i < 26; i++)
        g -= v[i]/t;

    return g <= 0;
}

int main()
{
    int t, n, i;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        v = vector<int> (26);
        for(auto u : s)
            v[u - 'a'] ++;

        for(i = n; i >= 1; i--)
        {
            if(check(i))
            {
                cout << i << endl;
                break;
            }
        }
    }
}
