#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, xll[3], yll[3], xur[3], yur[3];

    cin >> t;

    while(t--)
    {
        cin >> xll[0] >> yll[0] >> xur[0] >> yur[0];
        cin >> xll[1] >> yll[1] >> xur[1] >> yur[1];

        xll[2] = max(xll[0], xll[1]);
        yll[2] = max(yll[0], yll[1]);

        xur[2] = min(xur[0], xur[1]);
        yur[2] = min(yur[0], yur[1]);

        if(xll[2] < xur[2] && yll[2] < yur[2])
            cout << xll[2] << " " << yll[2] << " " << xur[2] << " " << yur[2] << "\n";
        else
            cout << "No Overlap\n";

        if(t)
            cout << "\n";
    }
}
