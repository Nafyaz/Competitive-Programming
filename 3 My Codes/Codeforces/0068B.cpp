#include<bits/stdc++.h>
using namespace std;

int n, k;
double a[10004];
bool isOk(double x)
{
    int i;
    double excess = 0, need = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] > x)
            excess += (a[i] - x);
        else
            need += (x - a[i]);
    }

//    cout << excess << " " << need << "\n";

    return excess*(100-k) >= need*100;
}

int main()
{
    int i;
    double l, r, mid;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];

//    cout << isOk(1.8812);

    l = 0;
    r = 1000;
    for(i = 0; i < 100; i++)
    {
        mid = (l+r)/2;
//        cout << "i: " << setw(3) << i << ";" << setw(9) << l << setw(9) << r << setw(9) << mid << " " << setw(3) << isOk(mid) << "\n";

        if(isOk(mid))
            l = mid;
        else
            r = mid;
    }

    cout << fixed << setprecision(7) << l;
}
