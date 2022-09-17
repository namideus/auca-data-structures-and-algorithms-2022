#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    long long int i, t, n, res, mx;

    cin >> t;

    while (t--)
    {
        cin >> n;

        res = (-1 + sqrt(1 + 8 * n)) / 2;

        cout << res << "\n";
    }
}