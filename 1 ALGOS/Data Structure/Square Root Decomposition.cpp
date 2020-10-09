#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a (n);

    int i, len = (int) sqrt (n + .0) + 1;
    vector<int> b (len);
    for (i = 0; i < n; i++)
        b[i/len] += a[i];

    while(1)
    {
        int l, r;

        int sum = 0;
        for (i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                sum += b[i / len];
                i += len;
            }
            else
            {
                sum += a[i];
                i++;
            }
        }
    }
}
