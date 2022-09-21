#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, m;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        cout << (n / 3) * (m / 3) << "\n";
    }
}