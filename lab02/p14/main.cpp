#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, ans, i, x, a, b, prev;

    cin >> n;

    cout << "Lumberjacks:\n";

    while (n--)
    {
        vector<int> v(10);

        for (auto &x : v)
            cin >> x;

        if (is_sorted(v.begin(), v.end()) || is_sorted(v.rbegin(), v.rend()))
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
}
