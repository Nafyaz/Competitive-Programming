#include<bits/stdc++.h>
using namespace std;

int w[102], p[102];

int main()
{
    int i, n, profitSum = 0, weightSum = 0, newProfit, possibleW;
    int low, high, mid;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cout << 1 << " " << i << " " << weightSum + 100 << endl;
        fflush(stdout);

        cin >> p[i];
        p[i] -= profitSum;

        low = 1;
        high = 100;

        while(low <= high)
        {
            mid = (low + high) / 2;

            cout << 1 << " " << i << " " << weightSum + mid << endl;
            fflush(stdout);

            cin >> newProfit;
            if(newProfit > profitSum)
            {
                possibleW = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        w[i] = possibleW;
        weightSum += possibleW;
        profitSum += p[i];
    }

    cout << 2 << endl;
    fflush(stdout);

    for(i = 1; i <= n; i++)
        cout << w[i] << " ";
    cout << endl;
    fflush(stdout);

    for(i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
    fflush(stdout);
}
