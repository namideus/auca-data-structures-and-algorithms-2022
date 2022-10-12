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

    int c, i, j, n, f, cnt, b, t, p1, p2, p3;
    double sum, avg;

    cin >> c;

    while (c--)
    {
        cin >> n;

        sum = 0;
        cnt = 0;
        vector<double> v(n);

        for (auto &x : v)
        {
            cin >> x;
            sum += x;
        }

        avg = sum / n;

        for (auto x : v)
            if (x > avg)
                cnt++;

        cout << fixed << setprecision(3) << (double)cnt / n * 100 << "%\n";
    }
}