#include<bits/stdc++.h>
using namespace std;
int a[4], total, ans, x;
void subset(int i, int sum)
{

    if(i == 4)
    {
//        cout << ++x << " " << sum << endl;
        if(2*sum == total)
            ans = 1;
        return;
    }
    subset(i+1, sum);
    subset(i+1, sum+a[i]);
}
int main()
{
    int i;
    for(i = 0; i < 4; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    subset(0, 0);
    ans? cout << "YES" : cout << "NO";
}
