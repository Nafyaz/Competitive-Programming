#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int n, i;
    double weight, price, k;
    vector <pair <double, double> > loot;

    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> weight >> price;
        loot.push_back({price/weight, weight});
    }

    sort(loot.begin(), loot.end(), greater<pair<double, double>>());

//    for(i = 0; i < n; i++)
//        cout << loot[i].ff << " " << loot[i].ss << "\n";

    double profit = 0;
    for(i = 0; i < n; i++)
    {
        weight = min(k, loot[i].ss);
        price = loot[i].ff * weight;

        k -= weight;
        profit += price;
    }

    cout << profit;
}
