#include<bits/stdc++.h>
using namespace std;

int n, rMat[50009][6];

bool isSup(int i, int j)
{
    int cnt = 0;
    for(int k = 1; k <= 5; k++)
    {
        if(rMat[i][k] < rMat[j][k])
            cnt++;
    }

    return cnt >= 3;
}

int main()
{
    long long x = 10e9+7;

    cout << x;

}
