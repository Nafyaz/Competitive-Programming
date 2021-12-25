#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n;
int m[200005], k[200005];
double expected_ans;
vector<int> message;

bool cmp(pair<double, int> a, pair<double, int> b)
{
    return a.ff > b.ff;
}

void func(int t)
{
    int i;
    map<int, double> expected;

    for(i = 0; i < n; i++)
    {
        if(k[i] < t)
            expected[m[i]] += (double)k[i]/t;
        else
            expected[m[i]] += 1;
    }

    vector<pair<double, int>> v;
    for(auto u : expected)
        v.push_back({u.ss, u.ff});

    if(v.size() < t)
        return;

    partial_sort(v.begin(), v.begin()+t, v.end(), cmp);

    double expected_val = 0;
    for(i = 0; i < t && i < v.size(); i++)
        expected_val += v[i].ff;

    if(expected_val > expected_ans)
    {
        expected_ans = expected_val;

        message.clear();
        for(i = 0; i < t && i < v.size(); i++)
            message.push_back(v[i].ss);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, t;
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> m[i] >> k[i];

    for(t = 1; t <= 20; t++)
        func(t);

    cout << message.size() << "\n";
    for(auto u : message)
        cout << u << " ";
}
