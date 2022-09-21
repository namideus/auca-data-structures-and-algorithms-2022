#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, m, x, i, hi, lo, prev, test = 1;

    cin >> t;

    while (t--)
    {
        cin >> n;

        hi = lo = 0;

        cin >> prev;

        for (i = 1; i < n; ++i)
        {
            cin >> x;

            if (prev < x)
                hi++;
            else if (prev > x)
                lo++;

            prev = x;
        }

        cout << "Case " << test << ": " << hi << " " << lo << "\n";

        test++;
    }
}