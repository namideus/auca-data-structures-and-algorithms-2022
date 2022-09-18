#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int x, y, z, test = 1, res, t, mn, mx;

    cin >> t;

    while (t--)
    {
        cin >> x >> y >> z;

        mn = min(x, min(y, z));
        mx = max(x, max(y, z));

        cout << "Case " << test << ": ";

        if (mn != x && mx != x)
            res = x;

        if (mn != y && mx != y)
            res = y;

        if (mn != z && mx != z)
            res = z;

        cout << res << "\n";

        ++test;
    }
}