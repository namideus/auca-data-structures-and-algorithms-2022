#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, m, x, i, pos, mx, mn;

    cin >> t;

    while (t--)
    {
        cin >> n;

        mx = 0;
        mn = 100;

        while (n--)
        {
            cin >> pos;
            mx = max(mx, pos);
            mn = min(mn, pos);
        }

        cout << 2 * (mx - mn) << "\n";
    }
}