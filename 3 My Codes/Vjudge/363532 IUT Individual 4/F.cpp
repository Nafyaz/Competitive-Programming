#include<bits/stdc++.h>
using namespace std;

int n, dp[];
vector<pair<int, int> > v;

int func(int i, int d, int f)
{
    if(i == n+1 || d <= f)
        return 0;

}

int main()
{
    int t, i, d, f;
    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> d >> f;
            v.push_back({d, f});
        }
        sort(v.begin(), v.end(), greater<int>());
        cin >> d >> f;
        cout << func(0, d, f) << endl;
    }
}
