#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double ha, hb, hc;
    double invha, invhb, invhc;
    double invhs, tmp;
    double area;

    cin >> n;

    while(1)
    {
        if(!n)
            break;

        cin >> ha >> hb >> hc;

        if(ha <= 0 || hb <= 0 || hc <= 0)
        {
            n--;
            cout << "These are invalid inputs!\n";
            continue;
        }

        invha = 1/ha;
        invhb = 1/hb;
        invhc = 1/hc;

        invhs = invha + invhb + invhc;
        tmp = invhs * (invhs-2*invha) * (invhs-2*invhb) * (invhs-2*invhc);

        if(tmp <= 0)
        {
            n--;
            cout << "These are invalid inputs!\n";
            continue;
        }

        area = 1/sqrt(tmp);

        cout << fixed;
        cout << setprecision(3) << area << "\n";
    }
}
