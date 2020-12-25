#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, ans[10];
    ans[2] = 10;
    ans[4] = 670;
    ans[6] = 0;
    ans[8] = 0;

    int sum3[28] = {0}, sum4[37] = {0};

    for(a = 0; a <= 9; a++)
    {
        for(b = 0; b <= 9; b++)
        {
            for(c = 0; c <= 9; c++)
            {
                sum3[a+b+c]++;
                for(d = 0; d <= 9; d++)
                    sum4[a+b+c+d]++;
            }
        }
    }

    for(a = 0; a < 28; a++)
        ans[6] += sum3[a]*sum3[a];

    for(a = 0; a < 37; a++)
        ans[8] += sum4[a]*sum4[a];

    cin >> a;
    cout << ans[a];
}
