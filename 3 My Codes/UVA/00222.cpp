#include<bits/stdc++.h>
using namespace std;

int n;
double stdis[55], stcost[55], dis, cap, rate;

double call(double g, int s)
{
    if(s == n)
        return 0;

    double ret = INT_MAX, fuel_need = (stdis[s+1] - stdis[s])/rate;

    if(g >= fuel_need)
        ret = min(ret, call(g - fuel_need, s+1));

    if(2 * g <= cap || fuel_need <= g)
        ret = min(ret, 2 + (cap - g)*stcost[s]/100 + call(cap - fuel_need, s+1));

//    cout << s << " " << ret << endl;
    return ret;
}

int main()
{
    int caseno = 0;
    double cost;
    while(1)
    {
        cin >> dis;
        if(dis < 0)
            return 0;
        cin >> cap >> rate >> cost >> n;

        for(int i = 0; i < n; i++)
            cin >> stdis[i] >> stcost[i];
        stdis[n] = dis;

        cout << "Data Set #" << ++caseno << endl;
        cout << "minimum cost = $" << fixed << setprecision(2) << cost + call(cap - stdis[0]/rate, 0) << endl;
    }
}
