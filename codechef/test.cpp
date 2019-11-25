#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);

    printf("%d", lower_bound(x.begin(), x.end(), 3));
}
