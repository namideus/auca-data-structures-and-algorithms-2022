#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, id, j, n, f, ans, d, k;
    char c;

    while (cin >> n && n)
    {
        cin >> c;

        vector<int> v(n);
        int cnt[10001];

        id = 0;
        for (auto &x : v)
            cin >> x, cnt[x] = id++;

        f = 1;
        for (i = 0; i < n && f; ++i)
            for (j = i + 1; j < n; ++j)
            {
                d = 2 * v[j] - v[i];

                if (d >= 0 && d < n)
                    if (cnt[d] > j)
                    {
                        f = 0;
                        break;
                    }
            }

        cout << (f ? "yes" : "no") << "\n";
    }
}
