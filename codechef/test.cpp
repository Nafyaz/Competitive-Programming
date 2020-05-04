#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {1, 2, 3}, idx[3] = {0, 1, 2}, i, j = 0;
    do
    {
        int temp[3], revidx[3];

        cout << j++ << ": ";

        for(i = 0; i < 3; i++)
            cout << idx[i] << " ";
        cout << ": ";

        for(i = 0; i < 3; i++)
            revidx[idx[i]] = i;

        for(i = 0; i < 3; i++)
            cout << revidx[i] << " ";
        cout << ": ";

        for(i = 0; i < 3; i++)
        {
            temp[revidx[i]] = a[revidx[(i+2)%3]];
        }

        for(i = 0; i < 3; i++)
            cout << temp[i] << " ";
        cout << endl;

    }while(next_permutation(idx, idx+3));
}
