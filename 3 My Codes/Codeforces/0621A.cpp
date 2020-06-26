#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <long long> v;
    long long n, i, x, sum = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        if(x%2 == 0)
            sum += x;
        else
            v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<long long>());

    for(i = 0; i < v.size()/2*2; i++)
        sum += v[i];

    cout << sum;
}
