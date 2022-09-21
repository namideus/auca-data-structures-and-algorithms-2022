#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, mx, test = 1;

    cin >> t;

    while (t--)
    {
        mx = 0;
        vector<pair<int, string>> v(10);

        for (auto &x : v)
        {
            cin >> x.second >> x.first;
            mx = max(x.first, mx);
        }

        cout << "Case #" << test << ":\n";

        for (auto x : v)
            if (mx == x.first)
                cout << x.second << "\n";

        ++test;
    }
}
