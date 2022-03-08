//https://codeforces.com/blog/entry/20762
//https://codeforces.com/contest/1/submission/13861109

#include<bits/stdc++.h>
using namespace std;
#define n 4
//index is ID

int prevRating[n] = {1500, 1851, 1953, 2382};
int actualPos[n] = {2, 4, 1, 3};
int newRating[n];

double Pij(int ri, int rj)
{
    //Probability that person with rating ri will be ahead of the person with rating rj;
    return 1 / (1 + pow(10, (rj-ri)/400.0));
}

double findSeed(int i, int ri)
{
    //what is the seed of ith person if he had rating ri

    double seed = 1;
    for(int j = 0; j < n; j++)
    {
        if(j != i)
            seed += Pij(prevRating[j], ri);
    }

    return seed;
}

int findNew(int i, double newSeed)
{
    //Finds new rating of person i

    double mnDiff = 1000, diff;
    int R;

    for(int r = 0; r < 4000; r++)
    {
        diff = abs(findSeed(i, r) - newSeed);

//        if(i == 0)
//            cout << newSeed << " " << r << " " << diff << "\n";

        if(diff < mnDiff)
        {
            mnDiff = diff;
            R = r;
        }
    }

    return R;
}

int main()
{
    double seed, newSeed;

    for(int i = 0; i < n; i++)
    {
        seed = findSeed(i, prevRating[i]);

        newSeed = sqrt(seed * actualPos[i]);

        newRating[i] = findNew(i, newSeed);
        cout << newRating[i] << " ";
    }
}
