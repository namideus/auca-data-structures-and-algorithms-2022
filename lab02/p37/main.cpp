#include <bits/stdc++.h>
#define INF 1e9

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, n, f;

    for (string es, os; cin >> es >> os;)
    {
        n = sz(os);
        f = 1;
        vector<int> c1(27, 0), c2(27, 0);

        for (i = 0; i < n; ++i)
            ++c1[es[i] - 'A'], ++c2[os[i] - 'A'];

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        for (i = 1; i <= 26; ++i)
            if (c1[i] != c2[i])
            {
                f = 0;
                break;
            }

        cout << (f ? "YES" : "NO") << "\n";
    }
}