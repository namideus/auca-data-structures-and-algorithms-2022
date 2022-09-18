#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, r, test = 1, res, f;
    double d;

    while (cin >> r >> n && n + r)
    {
        cout << "Case " << test << ": ";

        if (n >= r)
            cout << 0;
        else
        {
            d = r - n;

            if (d / n <= 26)
                cout << ceil(d / n);
            else
                cout << "impossible";
        }

        cout << "\n";

        ++test;
    }
}