#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, prize, choice, open;
    double total = 0;
    srand(time(NULL));
    for(i = 0; i < 100000; i++)
    {
        prize = rand()%3;
        choice = rand()%3;

        if(prize == choice)
            continue;
        else
            total++;

    }

    cout << total / i;
}
