#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, m, i, hi, lo, test = 1;

    cin >> t;

    while (t--)
    {
        cin >> n;

        vector<int> v(n);

        hi = lo = 0;

        for (auto &x : v)
            cin >> x;

        for (i = 1; i < n; i++)
        {
            if (v[i - 1] < v[i])
                hi++;
            else if (v[i - 1] > v[i])
                lo++;
        }

        cout << "Case " << test << ": " << hi << " " << lo << "\n";

        test++;
    }
}