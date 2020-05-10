#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k;
    double u, v;
    vector <pair <double, double> > loot;

    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> u >> v;
        loot.push_back(v/u, u);
    }

    sort(loot.begin(), loot.end(), greater<double>());

    double sum = 0, ;
    for(i = 0; i < n; i++)
    {
        if(sum > k)
            break;
        sum += loot[i].first();

    }
}
