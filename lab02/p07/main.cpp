#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b, res, f;

    while (cin >> a >> b && a + b >= 0)
    {
        cout << min(100 - b, abs(b - a));

        cout << "\n";
    }
}