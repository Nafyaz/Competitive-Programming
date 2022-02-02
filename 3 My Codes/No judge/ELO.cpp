//https://codeforces.com/blog/entry/20762

#include<bits/stdc++.h>
using namespace std;

//index is ID
//int previous[10] = {1000, 1100, 1150, 1150, 1200, 1250, 1450, 1500, 1700, 1800};
//int actual[10] = {9, 8, 5, 7, 10, 4, 3, 2, 1, 6};

int previous[10] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
int actual[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int New[10];

double Pij(int ri, int rj)
{
    //Probability that person with rating ri will be ahead of the person with rating rj;
    return 1 / (1 + pow(10, (rj-ri)/400.0));
}

double findSeed(int i, int ri)
{
    //what is the seed of ith person if he had rating ri

    double seed = 1;
    for(int j = 0; j < 10; j++)
    {
        if(j != i)
            seed += Pij(previous[j], ri);
    }

    return seed;
}

int findNew(int i, double m)
{
    //Finds new rating of person i

    double mnDiff = 1000, diff;
    int R;

    for(int r = 0; r < 4000; r++)
    {
        diff = abs(findSeed(i, r) - m);

//        if(i == 0)
//            cout << m << " " << r << " " << diff << "\n";

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
    double seed, m;

    for(int i = 0; i < 10; i++)
    {
        seed = findSeed(i, previous[i]);

        m = sqrt(seed * actual[i]);

        New[i] = findNew(i, m);
        cout << New[i] << " ";
    }

    cout << "\n";

    for(int i = 0; i < 10; i++)
        previous[i] = New[i];
    swap(actual[0], actual[1]);
    for(int i = 0; i < 10; i++)
    {
        seed = findSeed(i, previous[i]);

        m = sqrt(seed * actual[i]);

        New[i] = findNew(i, m);

        cout << New[i] << " ";
    }

}
