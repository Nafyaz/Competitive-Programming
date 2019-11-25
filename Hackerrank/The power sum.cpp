#include <bits/stdc++.h>

using namespace std;
int cnt = 0;

int ipow(int b, int e) {
    if (e == 0)
        return 1;
    return e == 0 ? 1 : b * ipow(b, e - 1);
}

int count_expressions(int x, int n, vector<int>& vals) {

    int s = 0;
    for (int v : vals) {
        s += ipow(v, n);
    }

    if (s == x) {
        return 1;
    } else {
        int answer = 0;
        int v = vals.empty() ? 1 : vals.back() + 1;
        while (s + ipow(v, n) <= x) {
            vals.push_back(v);
            answer += count_expressions(x, n, vals);
            vals.pop_back();
            v++;
        }
        return answer;
    }
}
// Complete the powerSum function below.
int powerSum(int X, int N) {
    vector <int> v;
    count_expressions(x, n, v);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
