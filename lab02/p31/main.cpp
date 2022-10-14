#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, n, d, sum;

    cout << "PERFECTION OUTPUT\n";

    while (cin >> d && d)
    {
        sum = 0;

        for (i = 1; i < d; ++i)
            if (d % i == 0)
                sum += i;

        cout << right << setw(5) << d;

        if (sum == d)
            cout << "  PERFECT";
        else if (sum > d)
            cout << "  ABUNDANT";
        else if (sum < d)
            cout << "  DEFICIENT";

        cout << "\n";
    }

    cout << "END OF OUTPUT\n";
}